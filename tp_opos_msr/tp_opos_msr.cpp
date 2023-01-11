// tp_opos_msr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


#include <opos/ct_opos_mgmt.h>

static void _cb_read_done(const std::wstring& s_iso1, const std::wstring& s_iso2, const std::wstring& s_iso3)
{
    if (s_iso1.empty()) {
        std::wcout << L"\n ISO1 : empty.\n";
    }
    else {
        std::wcout << L"\n ISO1 : " << s_iso1 << std::endl;
    }
    if (s_iso2.empty()) {
        std::wcout << L"\n ISO2 : empty.\n";
    }
    else {
        std::wcout << L"\n ISO2 : " << s_iso2 << std::endl;
    }
    if (s_iso3.empty()) {
        std::wcout << L"\n ISO3 : empty.\n";
    }
    else {
        std::wcout << L"\n ISO3 : " << s_iso3 << std::endl;
    }
}
int main()
{
    std::wcout << L"Hello World!\n";

    do {
        _ns_tools::ct_opos_mgmt *p_mgmt_msr = _ns_tools::ct_opos_mgmt::get_manager(_ns_tools::ct_opos_mgmt::type_opos_msr);
        if (!p_mgmt_msr) {
            std::wcout << L"ER : create mgmt msr.\n";
            continue;
        }

        _ns_tools::ct_opos_msr* p_msr = p_mgmt_msr->get_msr();
        if (!p_msr) {
            std::wcout << L"ER : create msr.\n";
            continue;
        }

        p_msr->set_read_done_callback(_cb_read_done);

        long l_result(OPOS_SUCCESS);
        
        l_result = p_msr->Open(L"Lpu230MSR").second;
        if (SUCCEEDED(l_result)) {
            std::wcout << L"OK : Open().\n";
        }
        l_result = p_msr->ClaimDevice(2000).second;
        if (SUCCEEDED(l_result)) {
            std::wcout << L"OK : ClaimDevice().\n";
        }

        p_msr->PutFreezeEvents(VARIANT_FALSE).
            PutTracksToRead(MSR_TR_1_2_3).
            PutTransmitSentinels(VARIANT_TRUE).
            PutErrorReportingType(MSR_ERT_CARD).
            PutDataEventEnabled(VARIANT_TRUE).
            PutDeviceEnabled(VARIANT_TRUE);
            

        for (int i = 0; i < 1; i++) {
            std::wcout << L"R" << i+1 <<L": read.\n";
            //p_msr->wait_event();
        }
        
        std::wcout << L"\n";
        for (int i = 0; i < 50; i++) {
            std::wcout << L"*";
            Sleep(1000);
        }
        std::wcout << L"\n";

        p_msr->ReleaseDevice();
        p_msr->Close();

        /*
        _ns_tools::ct_opos_mgmt::type_ptr ptr_keylock = _ns_tools::ct_opos_mgmt::get_manager(_ns_tools::ct_opos_mgmt::type_opos_keylock);
        if (!ptr_keylock) {
            std::wcout << L"ER : create mgmt keylock.\n";
            continue;
        }
        if (!ptr_keylock->is_ini()) {
            std::wcout << L"ER : ini create mgmt keylock.\n";
            continue;
        }
        */
    
        
    }while(false);
    _ns_tools::ct_opos_mgmt::get_manager(_ns_tools::ct_opos_mgmt::type_opos_msr, true);
    //_ns_tools::ct_opos_mgmt::get_manager(_ns_tools::ct_opos_mgmt::type_opos_all, true);
}
