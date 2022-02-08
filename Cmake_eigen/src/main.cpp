#include <iostream>
#include <Eigen/Dense>

#ifdef P7_LOGGER
#include "P7_Trace.h"
#include "P7_Telemetry.h"

void test_logger() 
{
    IP7_Client* l_pClient = NULL;

    IP7_Trace* l_pTrace = NULL;
    IP7_Trace::hModule l_hModule = NULL;

    IP7_Telemetry* l_pTelemetry = NULL;
    tUINT16            l_bTID1 = 0;
    tUINT16            l_bTID2 = 0;
    tUINT32            l_dwIdx = 0;
    stTelemetry_Conf   l_stConf = {};

    P7_Set_Crash_Handler();

    //create P7 client object
    l_pClient = P7_Create_Client(TM("/P7.Pool=32768"));

    if (NULL == l_pClient)
    {
        goto l_lblExit;
    }

    l_stConf.pContext = NULL;
    l_stConf.pEnable_Callback = &Telemetry_Enable;
    l_stConf.pTimestamp_Callback = NULL;
    l_stConf.qwTimestamp_Frequency = 0ull;
    l_stConf.pConnect_Callback = &Connect;

    //create P7 trace object 1
    l_pTrace = P7_Create_Trace(l_pClient, TM("Trace channel 1"));
    if (NULL == l_pTrace)
    {
        goto l_lblExit;
    }

    l_pTrace->Register_Thread(TM("Application"), 0);
    l_pTrace->Register_Module(TM("Main"), &l_hModule);

    //send few trace messages
    for (tUINT64 l_qwI = 0ULL; l_qwI < 100000ULL; l_qwI++)
    {
        l_pTrace->P7_TRACE(l_hModule, TM("Test trace message #%d\n, {%I64d}"), l_dwIdx++, l_qwI);
        l_pTrace->P7_INFO(l_hModule, TM("Test info message #%d, {%I64d}\n"), l_dwIdx++, l_qwI);
        l_pTrace->P7_DEBUG(l_hModule, TM("Test debug\n message #%d, {%I64d}"), l_dwIdx++, l_qwI);

        if (0xF == (rand() & 0xF))
        {
            l_pTrace->P7_WARNING(l_hModule, TM("Test warning message #%d, {%I64d}"), l_dwIdx++, l_qwI);
        }

        if (0xFF == (rand() & 0xFF))
        {
            l_pTrace->P7_ERROR(l_hModule, TM("Test error message #%d, {%I64d}"), l_dwIdx++, l_qwI);
        }

        if (0xFF0 == (rand() & 0xFFF))
        {
            l_pTrace->P7_CRITICAL(l_hModule, TM("Test critical message #%d, {%I64d}"), l_dwIdx++, l_qwI);
        }
    }

    l_pTrace->Unregister_Thread(0);
}

#endif

using Eigen::MatrixXd;

int main()
{
	MatrixXd m(2, 2);
	m(0, 0) = 3;
	m(1, 0) = 2.5;
	m(0, 1) = -1;
	m(1, 1) = m(1, 0) + m(0, 1);
	std::cout << m << std::endl;

#ifdef P7_LOGGER
    test_logger();
#endif
}