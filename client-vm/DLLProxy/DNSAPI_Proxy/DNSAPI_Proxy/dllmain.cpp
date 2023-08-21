// DLL proxying template made from a dnsapi.dll proxy
// Runs the conjure executable when called by a process
// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <windows.h>
#include <iostream>

#pragma comment (lib, "User32.lib")

//declare mutex name. This is used to make sure only one instance of Conjure is running on machine
const wchar_t* MUTEX_NAME = L"NSLOOKUPMUTEX";


int Main() {

    static HANDLE nMutex = NULL;

    while (TRUE) {

        Sleep(5000);

        //try to create mutex
        nMutex = CreateMutexW(NULL, TRUE, MUTEX_NAME);

        ///if mutex already exists, close handle and repeat while loop
        if (nMutex == NULL || GetLastError() == ERROR_ALREADY_EXISTS) {
            CloseHandle(nMutex);
        }
        else {
            //start executable and wait for process to finish.
            system("start /wait C:\\Users\\vboxuser\\source\\repos\\CSCode\\CSCode\\bin\\Debug\\net6.0\\CSCode.exe");
            CloseHandle(nMutex);
        }
    }
    return 1;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    //declare hMutex so it can be used across switch statement
    static HANDLE hMutex = NULL;

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:

        //Start Main() in a new thread
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Main, NULL, NULL, NULL);

        break;

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:

        //Release Mutex before DLL detaches
        if (hMutex != NULL) {
            ReleaseMutex(hMutex);
            CloseHandle(hMutex);
            hMutex = NULL;
        }

        break;

    }

    return TRUE;
}

//Insert export functions from getDLLFunc.py
#pragma comment(linker,"/export:AdaptiveTimeout_ClearInterfaceSpecificConfiguration=C:\\windows\\system32\\utilitycore.dll.AdaptiveTimeout_ClearInterfaceSpecificConfiguration,@1")
#pragma comment(linker,"/export:AdaptiveTimeout_ResetAdaptiveTimeout=C:\\windows\\system32\\utilitycore.dll.AdaptiveTimeout_ResetAdaptiveTimeout,@2")
#pragma comment(linker,"/export:AddRefQueryBlobEx=C:\\windows\\system32\\utilitycore.dll.AddRefQueryBlobEx,@3")
#pragma comment(linker,"/export:BreakRecordsIntoBlob=C:\\windows\\system32\\utilitycore.dll.BreakRecordsIntoBlob,@4")
#pragma comment(linker,"/export:Coalesce_UpdateNetVersion=C:\\windows\\system32\\utilitycore.dll.Coalesce_UpdateNetVersion,@5")
#pragma comment(linker,"/export:CombineRecordsInBlob=C:\\windows\\system32\\utilitycore.dll.CombineRecordsInBlob,@6")
#pragma comment(linker,"/export:DeRefQueryBlobEx=C:\\windows\\system32\\utilitycore.dll.DeRefQueryBlobEx,@7")
#pragma comment(linker,"/export:DelaySortDAServerlist=C:\\windows\\system32\\utilitycore.dll.DelaySortDAServerlist,@8")
#pragma comment(linker,"/export:DnsAcquireContextHandle_A=C:\\windows\\system32\\utilitycore.dll.DnsAcquireContextHandle_A,@9")
#pragma comment(linker,"/export:DnsAcquireContextHandle_W=C:\\windows\\system32\\utilitycore.dll.DnsAcquireContextHandle_W,@10")
#pragma comment(linker,"/export:DnsAllocateRecord=C:\\windows\\system32\\utilitycore.dll.DnsAllocateRecord,@11")
#pragma comment(linker,"/export:DnsApiAlloc=C:\\windows\\system32\\utilitycore.dll.DnsApiAlloc,@12")
#pragma comment(linker,"/export:DnsApiAllocZero=C:\\windows\\system32\\utilitycore.dll.DnsApiAllocZero,@13")
#pragma comment(linker,"/export:DnsApiFree=C:\\windows\\system32\\utilitycore.dll.DnsApiFree,@14")
#pragma comment(linker,"/export:DnsApiHeapReset=C:\\windows\\system32\\utilitycore.dll.DnsApiHeapReset,@15")
#pragma comment(linker,"/export:DnsApiRealloc=C:\\windows\\system32\\utilitycore.dll.DnsApiRealloc,@16")
#pragma comment(linker,"/export:DnsApiSetDebugGlobals=C:\\windows\\system32\\utilitycore.dll.DnsApiSetDebugGlobals,@17")
#pragma comment(linker,"/export:DnsAsyncRegisterHostAddrs=C:\\windows\\system32\\utilitycore.dll.DnsAsyncRegisterHostAddrs,@18")
#pragma comment(linker,"/export:DnsAsyncRegisterInit=C:\\windows\\system32\\utilitycore.dll.DnsAsyncRegisterInit,@19")
#pragma comment(linker,"/export:DnsAsyncRegisterTerm=C:\\windows\\system32\\utilitycore.dll.DnsAsyncRegisterTerm,@20")
#pragma comment(linker,"/export:DnsCancelQuery=C:\\windows\\system32\\utilitycore.dll.DnsCancelQuery,@21")
#pragma comment(linker,"/export:DnsCheckNrptRuleIntegrity=C:\\windows\\system32\\utilitycore.dll.DnsCheckNrptRuleIntegrity,@22")
#pragma comment(linker,"/export:DnsCheckNrptRules=C:\\windows\\system32\\utilitycore.dll.DnsCheckNrptRules,@23")
#pragma comment(linker,"/export:DnsCleanupTcpConnections=C:\\windows\\system32\\utilitycore.dll.DnsCleanupTcpConnections,@24")
#pragma comment(linker,"/export:DnsConnectionDeletePolicyEntries=C:\\windows\\system32\\utilitycore.dll.DnsConnectionDeletePolicyEntries,@25")
#pragma comment(linker,"/export:DnsConnectionDeletePolicyEntriesPrivate=C:\\windows\\system32\\utilitycore.dll.DnsConnectionDeletePolicyEntriesPrivate,@26")
#pragma comment(linker,"/export:DnsConnectionDeleteProxyInfo=C:\\windows\\system32\\utilitycore.dll.DnsConnectionDeleteProxyInfo,@27")
#pragma comment(linker,"/export:DnsConnectionFreeNameList=C:\\windows\\system32\\utilitycore.dll.DnsConnectionFreeNameList,@28")
#pragma comment(linker,"/export:DnsConnectionFreeProxyInfo=C:\\windows\\system32\\utilitycore.dll.DnsConnectionFreeProxyInfo,@29")
#pragma comment(linker,"/export:DnsConnectionFreeProxyInfoEx=C:\\windows\\system32\\utilitycore.dll.DnsConnectionFreeProxyInfoEx,@30")
#pragma comment(linker,"/export:DnsConnectionFreeProxyList=C:\\windows\\system32\\utilitycore.dll.DnsConnectionFreeProxyList,@31")
#pragma comment(linker,"/export:DnsConnectionGetHandleForHostUrlPrivate=C:\\windows\\system32\\utilitycore.dll.DnsConnectionGetHandleForHostUrlPrivate,@32")
#pragma comment(linker,"/export:DnsConnectionGetNameList=C:\\windows\\system32\\utilitycore.dll.DnsConnectionGetNameList,@33")
#pragma comment(linker,"/export:DnsConnectionGetProxyInfo=C:\\windows\\system32\\utilitycore.dll.DnsConnectionGetProxyInfo,@34")
#pragma comment(linker,"/export:DnsConnectionGetProxyInfoForHostUrl=C:\\windows\\system32\\utilitycore.dll.DnsConnectionGetProxyInfoForHostUrl,@35")
#pragma comment(linker,"/export:DnsConnectionGetProxyList=C:\\windows\\system32\\utilitycore.dll.DnsConnectionGetProxyList,@36")
#pragma comment(linker,"/export:DnsConnectionSetPolicyEntries=C:\\windows\\system32\\utilitycore.dll.DnsConnectionSetPolicyEntries,@37")
#pragma comment(linker,"/export:DnsConnectionSetPolicyEntriesPrivate=C:\\windows\\system32\\utilitycore.dll.DnsConnectionSetPolicyEntriesPrivate,@38")
#pragma comment(linker,"/export:DnsConnectionSetProxyInfo=C:\\windows\\system32\\utilitycore.dll.DnsConnectionSetProxyInfo,@39")
#pragma comment(linker,"/export:DnsConnectionUpdateIfIndexTable=C:\\windows\\system32\\utilitycore.dll.DnsConnectionUpdateIfIndexTable,@40")
#pragma comment(linker,"/export:DnsCopyStringEx=C:\\windows\\system32\\utilitycore.dll.DnsCopyStringEx,@41")
#pragma comment(linker,"/export:DnsCreateReverseNameStringForIpAddress=C:\\windows\\system32\\utilitycore.dll.DnsCreateReverseNameStringForIpAddress,@42")
#pragma comment(linker,"/export:DnsCreateStandardDnsNameCopy=C:\\windows\\system32\\utilitycore.dll.DnsCreateStandardDnsNameCopy,@43")
#pragma comment(linker,"/export:DnsCreateStringCopy=C:\\windows\\system32\\utilitycore.dll.DnsCreateStringCopy,@44")
#pragma comment(linker,"/export:DnsDeRegisterLocal=C:\\windows\\system32\\utilitycore.dll.DnsDeRegisterLocal,@45")
#pragma comment(linker,"/export:DnsDhcpRegisterAddrs=C:\\windows\\system32\\utilitycore.dll.DnsDhcpRegisterAddrs,@46")
#pragma comment(linker,"/export:DnsDhcpRegisterHostAddrs=C:\\windows\\system32\\utilitycore.dll.DnsDhcpRegisterHostAddrs,@47")
#pragma comment(linker,"/export:DnsDhcpRegisterInit=C:\\windows\\system32\\utilitycore.dll.DnsDhcpRegisterInit,@48")
#pragma comment(linker,"/export:DnsDhcpRegisterTerm=C:\\windows\\system32\\utilitycore.dll.DnsDhcpRegisterTerm,@49")
#pragma comment(linker,"/export:DnsDhcpRemoveRegistrations=C:\\windows\\system32\\utilitycore.dll.DnsDhcpRemoveRegistrations,@50")
#pragma comment(linker,"/export:DnsDhcpSrvRegisterHostAddr=C:\\windows\\system32\\utilitycore.dll.DnsDhcpSrvRegisterHostAddr,@51")
#pragma comment(linker,"/export:DnsDhcpSrvRegisterHostAddrEx=C:\\windows\\system32\\utilitycore.dll.DnsDhcpSrvRegisterHostAddrEx,@52")
#pragma comment(linker,"/export:DnsDhcpSrvRegisterHostName=C:\\windows\\system32\\utilitycore.dll.DnsDhcpSrvRegisterHostName,@53")
#pragma comment(linker,"/export:DnsDhcpSrvRegisterHostNameEx=C:\\windows\\system32\\utilitycore.dll.DnsDhcpSrvRegisterHostNameEx,@54")
#pragma comment(linker,"/export:DnsDhcpSrvRegisterInit=C:\\windows\\system32\\utilitycore.dll.DnsDhcpSrvRegisterInit,@55")
#pragma comment(linker,"/export:DnsDhcpSrvRegisterInitEx=C:\\windows\\system32\\utilitycore.dll.DnsDhcpSrvRegisterInitEx,@56")
#pragma comment(linker,"/export:DnsDhcpSrvRegisterInitialize=C:\\windows\\system32\\utilitycore.dll.DnsDhcpSrvRegisterInitialize,@57")
#pragma comment(linker,"/export:DnsDhcpSrvRegisterTerm=C:\\windows\\system32\\utilitycore.dll.DnsDhcpSrvRegisterTerm,@58")
#pragma comment(linker,"/export:DnsDisableIdnEncoding=C:\\windows\\system32\\utilitycore.dll.DnsDisableIdnEncoding,@59")
#pragma comment(linker,"/export:DnsDowncaseDnsNameLabel=C:\\windows\\system32\\utilitycore.dll.DnsDowncaseDnsNameLabel,@60")
#pragma comment(linker,"/export:DnsExtractRecordsFromMessage_UTF8=C:\\windows\\system32\\utilitycore.dll.DnsExtractRecordsFromMessage_UTF8,@61")
#pragma comment(linker,"/export:DnsExtractRecordsFromMessage_W=C:\\windows\\system32\\utilitycore.dll.DnsExtractRecordsFromMessage_W,@62")
#pragma comment(linker,"/export:DnsFindAuthoritativeZone=C:\\windows\\system32\\utilitycore.dll.DnsFindAuthoritativeZone,@63")
#pragma comment(linker,"/export:DnsFlushResolverCache=C:\\windows\\system32\\utilitycore.dll.DnsFlushResolverCache,@64")
#pragma comment(linker,"/export:DnsFlushResolverCacheEntry_A=C:\\windows\\system32\\utilitycore.dll.DnsFlushResolverCacheEntry_A,@65")
#pragma comment(linker,"/export:DnsFlushResolverCacheEntry_UTF8=C:\\windows\\system32\\utilitycore.dll.DnsFlushResolverCacheEntry_UTF8,@66")
#pragma comment(linker,"/export:DnsFlushResolverCacheEntry_W=C:\\windows\\system32\\utilitycore.dll.DnsFlushResolverCacheEntry_W,@67")
#pragma comment(linker,"/export:DnsFree=C:\\windows\\system32\\utilitycore.dll.DnsFree,@68")
#pragma comment(linker,"/export:DnsFreeAdaptersInfo=C:\\windows\\system32\\utilitycore.dll.DnsFreeAdaptersInfo,@69")
#pragma comment(linker,"/export:DnsFreeConfigStructure=C:\\windows\\system32\\utilitycore.dll.DnsFreeConfigStructure,@70")
#pragma comment(linker,"/export:DnsFreeNrptRule=C:\\windows\\system32\\utilitycore.dll.DnsFreeNrptRule,@71")
#pragma comment(linker,"/export:DnsFreeNrptRuleNamesList=C:\\windows\\system32\\utilitycore.dll.DnsFreeNrptRuleNamesList,@72")
#pragma comment(linker,"/export:DnsFreePolicyConfig=C:\\windows\\system32\\utilitycore.dll.DnsFreePolicyConfig,@73")
#pragma comment(linker,"/export:DnsFreeProxyName=C:\\windows\\system32\\utilitycore.dll.DnsFreeProxyName,@74")
#pragma comment(linker,"/export:DnsGetAdaptersInfo=C:\\windows\\system32\\utilitycore.dll.DnsGetAdaptersInfo,@75")
#pragma comment(linker,"/export:DnsGetApplicationIdentifier=C:\\windows\\system32\\utilitycore.dll.DnsGetApplicationIdentifier,@76")
#pragma comment(linker,"/export:DnsGetBufferLengthForStringCopy=C:\\windows\\system32\\utilitycore.dll.DnsGetBufferLengthForStringCopy,@77")
#pragma comment(linker,"/export:DnsGetCacheDataTable=C:\\windows\\system32\\utilitycore.dll.DnsGetCacheDataTable,@78")
#pragma comment(linker,"/export:DnsGetCacheDataTableEx=C:\\windows\\system32\\utilitycore.dll.DnsGetCacheDataTableEx,@79")
#pragma comment(linker,"/export:DnsGetDnsServerList=C:\\windows\\system32\\utilitycore.dll.DnsGetDnsServerList,@80")
#pragma comment(linker,"/export:DnsGetDomainName=C:\\windows\\system32\\utilitycore.dll.DnsGetDomainName,@81")
#pragma comment(linker,"/export:DnsGetInterfaceSettings=C:\\windows\\system32\\utilitycore.dll.DnsGetInterfaceSettings,@82")
#pragma comment(linker,"/export:DnsGetLastFailedUpdateInfo=C:\\windows\\system32\\utilitycore.dll.DnsGetLastFailedUpdateInfo,@83")
#pragma comment(linker,"/export:DnsGetNrptRuleNamesList=C:\\windows\\system32\\utilitycore.dll.DnsGetNrptRuleNamesList,@84")
#pragma comment(linker,"/export:DnsGetPolicyTableInfo=C:\\windows\\system32\\utilitycore.dll.DnsGetPolicyTableInfo,@85")
#pragma comment(linker,"/export:DnsGetPolicyTableInfoPrivate=C:\\windows\\system32\\utilitycore.dll.DnsGetPolicyTableInfoPrivate,@86")
#pragma comment(linker,"/export:DnsGetPrimaryDomainName_A=C:\\windows\\system32\\utilitycore.dll.DnsGetPrimaryDomainName_A,@87")
#pragma comment(linker,"/export:DnsGetProxyInfoPrivate=C:\\windows\\system32\\utilitycore.dll.DnsGetProxyInfoPrivate,@88")
#pragma comment(linker,"/export:DnsGetProxyInformation=C:\\windows\\system32\\utilitycore.dll.DnsGetProxyInformation,@89")
#pragma comment(linker,"/export:DnsGetQueryRetryTimeouts=C:\\windows\\system32\\utilitycore.dll.DnsGetQueryRetryTimeouts,@90")
#pragma comment(linker,"/export:DnsGetSettings=C:\\windows\\system32\\utilitycore.dll.DnsGetSettings,@91")
#pragma comment(linker,"/export:DnsGlobals=C:\\windows\\system32\\utilitycore.dll.DnsGlobals,@92")
#pragma comment(linker,"/export:DnsIpv6AddressToString=C:\\windows\\system32\\utilitycore.dll.DnsIpv6AddressToString,@93")
#pragma comment(linker,"/export:DnsIpv6StringToAddress=C:\\windows\\system32\\utilitycore.dll.DnsIpv6StringToAddress,@94")
#pragma comment(linker,"/export:DnsIsAMailboxType=C:\\windows\\system32\\utilitycore.dll.DnsIsAMailboxType,@95")
#pragma comment(linker,"/export:DnsIsNSECType=C:\\windows\\system32\\utilitycore.dll.DnsIsNSECType,@96")
#pragma comment(linker,"/export:DnsIsStatusRcode=C:\\windows\\system32\\utilitycore.dll.DnsIsStatusRcode,@97")
#pragma comment(linker,"/export:DnsIsStringCountValidForTextType=C:\\windows\\system32\\utilitycore.dll.DnsIsStringCountValidForTextType,@98")
#pragma comment(linker,"/export:DnsLogEvent=C:\\windows\\system32\\utilitycore.dll.DnsLogEvent,@99")
#pragma comment(linker,"/export:DnsMapRcodeToStatus=C:\\windows\\system32\\utilitycore.dll.DnsMapRcodeToStatus,@100")
#pragma comment(linker,"/export:DnsModifyRecordsInSet_A=C:\\windows\\system32\\utilitycore.dll.DnsModifyRecordsInSet_A,@101")
#pragma comment(linker,"/export:DnsModifyRecordsInSet_UTF8=C:\\windows\\system32\\utilitycore.dll.DnsModifyRecordsInSet_UTF8,@102")
#pragma comment(linker,"/export:DnsModifyRecordsInSet_W=C:\\windows\\system32\\utilitycore.dll.DnsModifyRecordsInSet_W,@103")
#pragma comment(linker,"/export:DnsNameCompareEx_A=C:\\windows\\system32\\utilitycore.dll.DnsNameCompareEx_A,@104")
#pragma comment(linker,"/export:DnsNameCompareEx_UTF8=C:\\windows\\system32\\utilitycore.dll.DnsNameCompareEx_UTF8,@105")
#pragma comment(linker,"/export:DnsNameCompareEx_W=C:\\windows\\system32\\utilitycore.dll.DnsNameCompareEx_W,@106")
#pragma comment(linker,"/export:DnsNameCompare_A=C:\\windows\\system32\\utilitycore.dll.DnsNameCompare_A,@107")
#pragma comment(linker,"/export:DnsNameCompare_UTF8=C:\\windows\\system32\\utilitycore.dll.DnsNameCompare_UTF8,@108")
#pragma comment(linker,"/export:DnsNameCompare_W=C:\\windows\\system32\\utilitycore.dll.DnsNameCompare_W,@109")
#pragma comment(linker,"/export:DnsNameCopy=C:\\windows\\system32\\utilitycore.dll.DnsNameCopy,@110")
#pragma comment(linker,"/export:DnsNameCopyAllocate=C:\\windows\\system32\\utilitycore.dll.DnsNameCopyAllocate,@111")
#pragma comment(linker,"/export:DnsNetworkInfo_CreateFromFAZ=C:\\windows\\system32\\utilitycore.dll.DnsNetworkInfo_CreateFromFAZ,@112")
#pragma comment(linker,"/export:DnsNetworkInformation_CreateFromFAZ=C:\\windows\\system32\\utilitycore.dll.DnsNetworkInformation_CreateFromFAZ,@113")
#pragma comment(linker,"/export:DnsNotifyResolver=C:\\windows\\system32\\utilitycore.dll.DnsNotifyResolver,@114")
#pragma comment(linker,"/export:DnsNotifyResolverClusterIp=C:\\windows\\system32\\utilitycore.dll.DnsNotifyResolverClusterIp,@115")
#pragma comment(linker,"/export:DnsNotifyResolverEx=C:\\windows\\system32\\utilitycore.dll.DnsNotifyResolverEx,@116")
#pragma comment(linker,"/export:DnsQueryConfig=C:\\windows\\system32\\utilitycore.dll.DnsQueryConfig,@117")
#pragma comment(linker,"/export:DnsQueryConfigAllocEx=C:\\windows\\system32\\utilitycore.dll.DnsQueryConfigAllocEx,@118")
#pragma comment(linker,"/export:DnsQueryConfigDword=C:\\windows\\system32\\utilitycore.dll.DnsQueryConfigDword,@119")
#pragma comment(linker,"/export:DnsQueryEx=C:\\windows\\system32\\utilitycore.dll.DnsQueryEx,@120")
#pragma comment(linker,"/export:DnsQueryExA=C:\\windows\\system32\\utilitycore.dll.DnsQueryExA,@121")
#pragma comment(linker,"/export:DnsQueryExUTF8=C:\\windows\\system32\\utilitycore.dll.DnsQueryExUTF8,@122")
#pragma comment(linker,"/export:DnsQueryExW=C:\\windows\\system32\\utilitycore.dll.DnsQueryExW,@123")
#pragma comment(linker,"/export:DnsQuery_A=C:\\windows\\system32\\utilitycore.dll.DnsQuery_A,@124")
#pragma comment(linker,"/export:DnsQuery_UTF8=C:\\windows\\system32\\utilitycore.dll.DnsQuery_UTF8,@125")
#pragma comment(linker,"/export:DnsQuery_W=C:\\windows\\system32\\utilitycore.dll.DnsQuery_W,@126")
#pragma comment(linker,"/export:DnsRecordBuild_UTF8=C:\\windows\\system32\\utilitycore.dll.DnsRecordBuild_UTF8,@127")
#pragma comment(linker,"/export:DnsRecordBuild_W=C:\\windows\\system32\\utilitycore.dll.DnsRecordBuild_W,@128")
#pragma comment(linker,"/export:DnsRecordCompare=C:\\windows\\system32\\utilitycore.dll.DnsRecordCompare,@129")
#pragma comment(linker,"/export:DnsRecordCopyEx=C:\\windows\\system32\\utilitycore.dll.DnsRecordCopyEx,@130")
#pragma comment(linker,"/export:DnsRecordListFree=C:\\windows\\system32\\utilitycore.dll.DnsRecordListFree,@131")
#pragma comment(linker,"/export:DnsRecordListUnmapV4MappedAAAAInPlace=C:\\windows\\system32\\utilitycore.dll.DnsRecordListUnmapV4MappedAAAAInPlace,@132")
#pragma comment(linker,"/export:DnsRecordSetCompare=C:\\windows\\system32\\utilitycore.dll.DnsRecordSetCompare,@133")
#pragma comment(linker,"/export:DnsRecordSetCopyEx=C:\\windows\\system32\\utilitycore.dll.DnsRecordSetCopyEx,@134")
#pragma comment(linker,"/export:DnsRecordSetDetach=C:\\windows\\system32\\utilitycore.dll.DnsRecordSetDetach,@135")
#pragma comment(linker,"/export:DnsRecordStringForType=C:\\windows\\system32\\utilitycore.dll.DnsRecordStringForType,@136")
#pragma comment(linker,"/export:DnsRecordStringForWritableType=C:\\windows\\system32\\utilitycore.dll.DnsRecordStringForWritableType,@137")
#pragma comment(linker,"/export:DnsRecordTypeForName=C:\\windows\\system32\\utilitycore.dll.DnsRecordTypeForName,@138")
#pragma comment(linker,"/export:DnsRegisterLocal=C:\\windows\\system32\\utilitycore.dll.DnsRegisterLocal,@139")
#pragma comment(linker,"/export:DnsReleaseContextHandle=C:\\windows\\system32\\utilitycore.dll.DnsReleaseContextHandle,@140")
#pragma comment(linker,"/export:DnsRemoveNrptRule=C:\\windows\\system32\\utilitycore.dll.DnsRemoveNrptRule,@141")
#pragma comment(linker,"/export:DnsRemoveRegistrations=C:\\windows\\system32\\utilitycore.dll.DnsRemoveRegistrations,@142")
#pragma comment(linker,"/export:DnsReplaceRecordSetA=C:\\windows\\system32\\utilitycore.dll.DnsReplaceRecordSetA,@143")
#pragma comment(linker,"/export:DnsReplaceRecordSetUTF8=C:\\windows\\system32\\utilitycore.dll.DnsReplaceRecordSetUTF8,@144")
#pragma comment(linker,"/export:DnsReplaceRecordSetW=C:\\windows\\system32\\utilitycore.dll.DnsReplaceRecordSetW,@145")
#pragma comment(linker,"/export:DnsResetQueryRetryTimeouts=C:\\windows\\system32\\utilitycore.dll.DnsResetQueryRetryTimeouts,@146")
#pragma comment(linker,"/export:DnsResolverOp=C:\\windows\\system32\\utilitycore.dll.DnsResolverOp,@147")
#pragma comment(linker,"/export:DnsResolverQueryHvsi=C:\\windows\\system32\\utilitycore.dll.DnsResolverQueryHvsi,@148")
#pragma comment(linker,"/export:DnsScreenLocalAddrsForRegistration=C:\\windows\\system32\\utilitycore.dll.DnsScreenLocalAddrsForRegistration,@149")
#pragma comment(linker,"/export:DnsServiceBrowse=C:\\windows\\system32\\utilitycore.dll.DnsServiceBrowse,@150")
#pragma comment(linker,"/export:DnsServiceBrowseCancel=C:\\windows\\system32\\utilitycore.dll.DnsServiceBrowseCancel,@151")
#pragma comment(linker,"/export:DnsServiceConstructInstance=C:\\windows\\system32\\utilitycore.dll.DnsServiceConstructInstance,@152")
#pragma comment(linker,"/export:DnsServiceCopyInstance=C:\\windows\\system32\\utilitycore.dll.DnsServiceCopyInstance,@153")
#pragma comment(linker,"/export:DnsServiceDeRegister=C:\\windows\\system32\\utilitycore.dll.DnsServiceDeRegister,@154")
#pragma comment(linker,"/export:DnsServiceFreeInstance=C:\\windows\\system32\\utilitycore.dll.DnsServiceFreeInstance,@155")
#pragma comment(linker,"/export:DnsServiceRegister=C:\\windows\\system32\\utilitycore.dll.DnsServiceRegister,@156")
#pragma comment(linker,"/export:DnsServiceRegisterCancel=C:\\windows\\system32\\utilitycore.dll.DnsServiceRegisterCancel,@157")
#pragma comment(linker,"/export:DnsServiceResolve=C:\\windows\\system32\\utilitycore.dll.DnsServiceResolve,@158")
#pragma comment(linker,"/export:DnsServiceResolveCancel=C:\\windows\\system32\\utilitycore.dll.DnsServiceResolveCancel,@159")
#pragma comment(linker,"/export:DnsSetConfigDword=C:\\windows\\system32\\utilitycore.dll.DnsSetConfigDword,@160")
#pragma comment(linker,"/export:DnsSetConfigValue=C:\\windows\\system32\\utilitycore.dll.DnsSetConfigValue,@161")
#pragma comment(linker,"/export:DnsSetInterfaceSettings=C:\\windows\\system32\\utilitycore.dll.DnsSetInterfaceSettings,@162")
#pragma comment(linker,"/export:DnsSetNrptRule=C:\\windows\\system32\\utilitycore.dll.DnsSetNrptRule,@163")
#pragma comment(linker,"/export:DnsSetNrptRules=C:\\windows\\system32\\utilitycore.dll.DnsSetNrptRules,@164")
#pragma comment(linker,"/export:DnsSetQueryRetryTimeouts=C:\\windows\\system32\\utilitycore.dll.DnsSetQueryRetryTimeouts,@165")
#pragma comment(linker,"/export:DnsSetSettings=C:\\windows\\system32\\utilitycore.dll.DnsSetSettings,@166")
#pragma comment(linker,"/export:DnsStartMulticastQuery=C:\\windows\\system32\\utilitycore.dll.DnsStartMulticastQuery,@167")
#pragma comment(linker,"/export:DnsStatusString=C:\\windows\\system32\\utilitycore.dll.DnsStatusString,@168")
#pragma comment(linker,"/export:DnsStopMulticastQuery=C:\\windows\\system32\\utilitycore.dll.DnsStopMulticastQuery,@169")
#pragma comment(linker,"/export:DnsStringCopyAllocateEx=C:\\windows\\system32\\utilitycore.dll.DnsStringCopyAllocateEx,@170")
#pragma comment(linker,"/export:DnsTraceServerConfig=C:\\windows\\system32\\utilitycore.dll.DnsTraceServerConfig,@171")
#pragma comment(linker,"/export:DnsUnicodeToUtf8=C:\\windows\\system32\\utilitycore.dll.DnsUnicodeToUtf8,@172")
#pragma comment(linker,"/export:DnsUpdate=C:\\windows\\system32\\utilitycore.dll.DnsUpdate,@173")
#pragma comment(linker,"/export:DnsUpdateMachinePresence=C:\\windows\\system32\\utilitycore.dll.DnsUpdateMachinePresence,@174")
#pragma comment(linker,"/export:DnsUpdateTest_A=C:\\windows\\system32\\utilitycore.dll.DnsUpdateTest_A,@175")
#pragma comment(linker,"/export:DnsUpdateTest_UTF8=C:\\windows\\system32\\utilitycore.dll.DnsUpdateTest_UTF8,@176")
#pragma comment(linker,"/export:DnsUpdateTest_W=C:\\windows\\system32\\utilitycore.dll.DnsUpdateTest_W,@177")
#pragma comment(linker,"/export:DnsUtf8ToUnicode=C:\\windows\\system32\\utilitycore.dll.DnsUtf8ToUnicode,@178")
#pragma comment(linker,"/export:DnsValidateNameOrIp_TempW=C:\\windows\\system32\\utilitycore.dll.DnsValidateNameOrIp_TempW,@179")
#pragma comment(linker,"/export:DnsValidateName_A=C:\\windows\\system32\\utilitycore.dll.DnsValidateName_A,@180")
#pragma comment(linker,"/export:DnsValidateName_UTF8=C:\\windows\\system32\\utilitycore.dll.DnsValidateName_UTF8,@181")
#pragma comment(linker,"/export:DnsValidateName_W=C:\\windows\\system32\\utilitycore.dll.DnsValidateName_W,@182")
#pragma comment(linker,"/export:DnsValidateServerArray_A=C:\\windows\\system32\\utilitycore.dll.DnsValidateServerArray_A,@183")
#pragma comment(linker,"/export:DnsValidateServerArray_W=C:\\windows\\system32\\utilitycore.dll.DnsValidateServerArray_W,@184")
#pragma comment(linker,"/export:DnsValidateServerStatus=C:\\windows\\system32\\utilitycore.dll.DnsValidateServerStatus,@185")
#pragma comment(linker,"/export:DnsValidateServer_A=C:\\windows\\system32\\utilitycore.dll.DnsValidateServer_A,@186")
#pragma comment(linker,"/export:DnsValidateServer_W=C:\\windows\\system32\\utilitycore.dll.DnsValidateServer_W,@187")
#pragma comment(linker,"/export:DnsValidateUtf8Byte=C:\\windows\\system32\\utilitycore.dll.DnsValidateUtf8Byte,@188")
#pragma comment(linker,"/export:DnsWriteQuestionToBuffer_UTF8=C:\\windows\\system32\\utilitycore.dll.DnsWriteQuestionToBuffer_UTF8,@189")
#pragma comment(linker,"/export:DnsWriteQuestionToBuffer_W=C:\\windows\\system32\\utilitycore.dll.DnsWriteQuestionToBuffer_W,@190")
#pragma comment(linker,"/export:DnsWriteReverseNameStringForIpAddress=C:\\windows\\system32\\utilitycore.dll.DnsWriteReverseNameStringForIpAddress,@191")
#pragma comment(linker,"/export:Dns_AddRecordsToMessage=C:\\windows\\system32\\utilitycore.dll.Dns_AddRecordsToMessage,@192")
#pragma comment(linker,"/export:Dns_AllocateMsgBuf=C:\\windows\\system32\\utilitycore.dll.Dns_AllocateMsgBuf,@193")
#pragma comment(linker,"/export:Dns_BuildPacket=C:\\windows\\system32\\utilitycore.dll.Dns_BuildPacket,@194")
#pragma comment(linker,"/export:Dns_CacheServiceCleanup=C:\\windows\\system32\\utilitycore.dll.Dns_CacheServiceCleanup,@195")
#pragma comment(linker,"/export:Dns_CacheServiceInit=C:\\windows\\system32\\utilitycore.dll.Dns_CacheServiceInit,@196")
#pragma comment(linker,"/export:Dns_CacheServiceStopIssued=C:\\windows\\system32\\utilitycore.dll.Dns_CacheServiceStopIssued,@197")
#pragma comment(linker,"/export:Dns_CleanupWinsock=C:\\windows\\system32\\utilitycore.dll.Dns_CleanupWinsock,@198")
#pragma comment(linker,"/export:Dns_CloseConnection=C:\\windows\\system32\\utilitycore.dll.Dns_CloseConnection,@199")
#pragma comment(linker,"/export:Dns_CloseSocket=C:\\windows\\system32\\utilitycore.dll.Dns_CloseSocket,@200")
#pragma comment(linker,"/export:Dns_CreateMulticastSocket=C:\\windows\\system32\\utilitycore.dll.Dns_CreateMulticastSocket,@201")
#pragma comment(linker,"/export:Dns_CreateSocket=C:\\windows\\system32\\utilitycore.dll.Dns_CreateSocket,@202")
#pragma comment(linker,"/export:Dns_CreateSocketEx=C:\\windows\\system32\\utilitycore.dll.Dns_CreateSocketEx,@203")
#pragma comment(linker,"/export:Dns_ExtractRecordsFromMessage=C:\\windows\\system32\\utilitycore.dll.Dns_ExtractRecordsFromMessage,@204")
#pragma comment(linker,"/export:Dns_FindAuthoritativeZoneLib=C:\\windows\\system32\\utilitycore.dll.Dns_FindAuthoritativeZoneLib,@205")
#pragma comment(linker,"/export:Dns_FreeMsgBuf=C:\\windows\\system32\\utilitycore.dll.Dns_FreeMsgBuf,@206")
#pragma comment(linker,"/export:Dns_GetRandomXid=C:\\windows\\system32\\utilitycore.dll.Dns_GetRandomXid,@207")
#pragma comment(linker,"/export:Dns_InitializeMsgBuf=C:\\windows\\system32\\utilitycore.dll.Dns_InitializeMsgBuf,@208")
#pragma comment(linker,"/export:Dns_InitializeMsgRemoteSockaddr=C:\\windows\\system32\\utilitycore.dll.Dns_InitializeMsgRemoteSockaddr,@209")
#pragma comment(linker,"/export:Dns_InitializeWinsock=C:\\windows\\system32\\utilitycore.dll.Dns_InitializeWinsock,@210")
#pragma comment(linker,"/export:Dns_OpenTcpConnectionAndSend=C:\\windows\\system32\\utilitycore.dll.Dns_OpenTcpConnectionAndSend,@211")
#pragma comment(linker,"/export:Dns_ParseMessage=C:\\windows\\system32\\utilitycore.dll.Dns_ParseMessage,@212")
#pragma comment(linker,"/export:Dns_ParsePacketRecord=C:\\windows\\system32\\utilitycore.dll.Dns_ParsePacketRecord,@213")
#pragma comment(linker,"/export:Dns_PingAdapterServers=C:\\windows\\system32\\utilitycore.dll.Dns_PingAdapterServers,@214")
#pragma comment(linker,"/export:Dns_ReadPacketName=C:\\windows\\system32\\utilitycore.dll.Dns_ReadPacketName,@215")
#pragma comment(linker,"/export:Dns_ReadPacketNameAllocate=C:\\windows\\system32\\utilitycore.dll.Dns_ReadPacketNameAllocate,@216")
#pragma comment(linker,"/export:Dns_ReadRecordStructureFromPacket=C:\\windows\\system32\\utilitycore.dll.Dns_ReadRecordStructureFromPacket,@217")
#pragma comment(linker,"/export:Dns_RecvTcp=C:\\windows\\system32\\utilitycore.dll.Dns_RecvTcp,@218")
#pragma comment(linker,"/export:Dns_ResetNetworkInfo=C:\\windows\\system32\\utilitycore.dll.Dns_ResetNetworkInfo,@219")
#pragma comment(linker,"/export:Dns_SendAndRecvUdp=C:\\windows\\system32\\utilitycore.dll.Dns_SendAndRecvUdp,@220")
#pragma comment(linker,"/export:Dns_SendEx=C:\\windows\\system32\\utilitycore.dll.Dns_SendEx,@221")
#pragma comment(linker,"/export:Dns_SetRecordDatalength=C:\\windows\\system32\\utilitycore.dll.Dns_SetRecordDatalength,@222")
#pragma comment(linker,"/export:Dns_SetRecordsSection=C:\\windows\\system32\\utilitycore.dll.Dns_SetRecordsSection,@223")
#pragma comment(linker,"/export:Dns_SetRecordsTtl=C:\\windows\\system32\\utilitycore.dll.Dns_SetRecordsTtl,@224")
#pragma comment(linker,"/export:Dns_SkipPacketName=C:\\windows\\system32\\utilitycore.dll.Dns_SkipPacketName,@225")
#pragma comment(linker,"/export:Dns_SkipToRecord=C:\\windows\\system32\\utilitycore.dll.Dns_SkipToRecord,@226")
#pragma comment(linker,"/export:Dns_UpdateLib=C:\\windows\\system32\\utilitycore.dll.Dns_UpdateLib,@227")
#pragma comment(linker,"/export:Dns_UpdateLibEx=C:\\windows\\system32\\utilitycore.dll.Dns_UpdateLibEx,@228")
#pragma comment(linker,"/export:Dns_WriteDottedNameToPacket=C:\\windows\\system32\\utilitycore.dll.Dns_WriteDottedNameToPacket,@229")
#pragma comment(linker,"/export:Dns_WriteQuestionToMessage=C:\\windows\\system32\\utilitycore.dll.Dns_WriteQuestionToMessage,@230")
#pragma comment(linker,"/export:Dns_WriteRecordStructureToPacketEx=C:\\windows\\system32\\utilitycore.dll.Dns_WriteRecordStructureToPacketEx,@231")
#pragma comment(linker,"/export:ExtraInfo_Init=C:\\windows\\system32\\utilitycore.dll.ExtraInfo_Init,@232")
#pragma comment(linker,"/export:Faz_AreServerListsInSameNameSpace=C:\\windows\\system32\\utilitycore.dll.Faz_AreServerListsInSameNameSpace,@233")
#pragma comment(linker,"/export:FlushDnsPolicyUnreachableStatus=C:\\windows\\system32\\utilitycore.dll.FlushDnsPolicyUnreachableStatus,@234")
#pragma comment(linker,"/export:GetCurrentTimeInSeconds=C:\\windows\\system32\\utilitycore.dll.GetCurrentTimeInSeconds,@235")
#pragma comment(linker,"/export:HostsFile_Close=C:\\windows\\system32\\utilitycore.dll.HostsFile_Close,@236")
#pragma comment(linker,"/export:HostsFile_Open=C:\\windows\\system32\\utilitycore.dll.HostsFile_Open,@237")
#pragma comment(linker,"/export:HostsFile_ReadLine=C:\\windows\\system32\\utilitycore.dll.HostsFile_ReadLine,@238")
#pragma comment(linker,"/export:IpHelp_IsAddrOnLink=C:\\windows\\system32\\utilitycore.dll.IpHelp_IsAddrOnLink,@239")
#pragma comment(linker,"/export:Local_GetRecordsForLocalName=C:\\windows\\system32\\utilitycore.dll.Local_GetRecordsForLocalName,@240")
#pragma comment(linker,"/export:Local_GetRecordsForLocalNameEx=C:\\windows\\system32\\utilitycore.dll.Local_GetRecordsForLocalNameEx,@241")
#pragma comment(linker,"/export:NetInfo_Build=C:\\windows\\system32\\utilitycore.dll.NetInfo_Build,@242")
#pragma comment(linker,"/export:NetInfo_Clean=C:\\windows\\system32\\utilitycore.dll.NetInfo_Clean,@243")
#pragma comment(linker,"/export:NetInfo_Copy=C:\\windows\\system32\\utilitycore.dll.NetInfo_Copy,@244")
#pragma comment(linker,"/export:NetInfo_CopyNetworkIndex=C:\\windows\\system32\\utilitycore.dll.NetInfo_CopyNetworkIndex,@245")
#pragma comment(linker,"/export:NetInfo_CreatePerNetworkNetinfo=C:\\windows\\system32\\utilitycore.dll.NetInfo_CreatePerNetworkNetinfo,@246")
#pragma comment(linker,"/export:NetInfo_Free=C:\\windows\\system32\\utilitycore.dll.NetInfo_Free,@247")
#pragma comment(linker,"/export:NetInfo_GetAdapterByAddress=C:\\windows\\system32\\utilitycore.dll.NetInfo_GetAdapterByAddress,@248")
#pragma comment(linker,"/export:NetInfo_GetAdapterByInterfaceIndex=C:\\windows\\system32\\utilitycore.dll.NetInfo_GetAdapterByInterfaceIndex,@249")
#pragma comment(linker,"/export:NetInfo_GetAdapterByName=C:\\windows\\system32\\utilitycore.dll.NetInfo_GetAdapterByName,@250")
#pragma comment(linker,"/export:NetInfo_IsAddrConfig=C:\\windows\\system32\\utilitycore.dll.NetInfo_IsAddrConfig,@251")
#pragma comment(linker,"/export:NetInfo_IsForUpdate=C:\\windows\\system32\\utilitycore.dll.NetInfo_IsForUpdate,@252")
#pragma comment(linker,"/export:NetInfo_IsTcpipConfigChange=C:\\windows\\system32\\utilitycore.dll.NetInfo_IsTcpipConfigChange,@253")
#pragma comment(linker,"/export:NetInfo_ResetServerPriorities=C:\\windows\\system32\\utilitycore.dll.NetInfo_ResetServerPriorities,@254")
#pragma comment(linker,"/export:NetInfo_UpdateDnsInterfaceConfigChange=C:\\windows\\system32\\utilitycore.dll.NetInfo_UpdateDnsInterfaceConfigChange,@255")
#pragma comment(linker,"/export:NetInfo_UpdateNetworkProperties=C:\\windows\\system32\\utilitycore.dll.NetInfo_UpdateNetworkProperties,@256")
#pragma comment(linker,"/export:NetInfo_UpdateServerReachability=C:\\windows\\system32\\utilitycore.dll.NetInfo_UpdateServerReachability,@257")
#pragma comment(linker,"/export:QueryDirectEx=C:\\windows\\system32\\utilitycore.dll.QueryDirectEx,@258")
#pragma comment(linker,"/export:Query_Cancel=C:\\windows\\system32\\utilitycore.dll.Query_Cancel,@259")
#pragma comment(linker,"/export:Query_Main=C:\\windows\\system32\\utilitycore.dll.Query_Main,@260")
#pragma comment(linker,"/export:Reg_FreeUpdateInfo=C:\\windows\\system32\\utilitycore.dll.Reg_FreeUpdateInfo,@261")
#pragma comment(linker,"/export:Reg_GetValueEx=C:\\windows\\system32\\utilitycore.dll.Reg_GetValueEx,@262")
#pragma comment(linker,"/export:Reg_ReadGlobalsEx=C:\\windows\\system32\\utilitycore.dll.Reg_ReadGlobalsEx,@263")
#pragma comment(linker,"/export:Reg_ReadUpdateInfo=C:\\windows\\system32\\utilitycore.dll.Reg_ReadUpdateInfo,@264")
#pragma comment(linker,"/export:Security_ContextListTimeout=C:\\windows\\system32\\utilitycore.dll.Security_ContextListTimeout,@265")
#pragma comment(linker,"/export:Send_AndRecvUdpWithParam=C:\\windows\\system32\\utilitycore.dll.Send_AndRecvUdpWithParam,@266")
#pragma comment(linker,"/export:Send_MessagePrivate=C:\\windows\\system32\\utilitycore.dll.Send_MessagePrivate,@267")
#pragma comment(linker,"/export:Send_MessagePrivateEx=C:\\windows\\system32\\utilitycore.dll.Send_MessagePrivateEx,@268")
#pragma comment(linker,"/export:Send_OpenTcpConnectionAndSend=C:\\windows\\system32\\utilitycore.dll.Send_OpenTcpConnectionAndSend,@269")
#pragma comment(linker,"/export:Socket_CacheCleanup=C:\\windows\\system32\\utilitycore.dll.Socket_CacheCleanup,@270")
#pragma comment(linker,"/export:Socket_CacheInit=C:\\windows\\system32\\utilitycore.dll.Socket_CacheInit,@271")
#pragma comment(linker,"/export:Socket_CleanupWinsock=C:\\windows\\system32\\utilitycore.dll.Socket_CleanupWinsock,@272")
#pragma comment(linker,"/export:Socket_ClearMessageSockets=C:\\windows\\system32\\utilitycore.dll.Socket_ClearMessageSockets,@273")
#pragma comment(linker,"/export:Socket_CloseEx=C:\\windows\\system32\\utilitycore.dll.Socket_CloseEx,@274")
#pragma comment(linker,"/export:Socket_CloseMessageSockets=C:\\windows\\system32\\utilitycore.dll.Socket_CloseMessageSockets,@275")
#pragma comment(linker,"/export:Socket_Create=C:\\windows\\system32\\utilitycore.dll.Socket_Create,@276")
#pragma comment(linker,"/export:Socket_CreateMulticast=C:\\windows\\system32\\utilitycore.dll.Socket_CreateMulticast,@277")
#pragma comment(linker,"/export:Socket_InitWinsock=C:\\windows\\system32\\utilitycore.dll.Socket_InitWinsock,@278")
#pragma comment(linker,"/export:Socket_JoinMulticast=C:\\windows\\system32\\utilitycore.dll.Socket_JoinMulticast,@279")
#pragma comment(linker,"/export:Socket_RecvFrom=C:\\windows\\system32\\utilitycore.dll.Socket_RecvFrom,@280")
#pragma comment(linker,"/export:Socket_SetMulticastInterface=C:\\windows\\system32\\utilitycore.dll.Socket_SetMulticastInterface,@281")
#pragma comment(linker,"/export:Socket_SetMulticastLoopBack=C:\\windows\\system32\\utilitycore.dll.Socket_SetMulticastLoopBack,@282")
#pragma comment(linker,"/export:Socket_SetTtl=C:\\windows\\system32\\utilitycore.dll.Socket_SetTtl,@283")
#pragma comment(linker,"/export:Socket_TcpListen=C:\\windows\\system32\\utilitycore.dll.Socket_TcpListen,@284")
#pragma comment(linker,"/export:Trace_Reset=C:\\windows\\system32\\utilitycore.dll.Trace_Reset,@285")
#pragma comment(linker,"/export:Update_ReplaceAddressRecordsW=C:\\windows\\system32\\utilitycore.dll.Update_ReplaceAddressRecordsW,@286")
#pragma comment(linker,"/export:Util_IsIp6Running=C:\\windows\\system32\\utilitycore.dll.Util_IsIp6Running,@287")
#pragma comment(linker,"/export:Util_IsRunningOnXboxOne=C:\\windows\\system32\\utilitycore.dll.Util_IsRunningOnXboxOne,@288")
#pragma comment(linker,"/export:WriteDnsNrptRulesToRegistry=C:\\windows\\system32\\utilitycore.dll.WriteDnsNrptRulesToRegistry,@289")
