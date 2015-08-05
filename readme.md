# V8/Node.js Debugging Extension
A Windbg Extension to debugging V8/Node.js running on Windows.

This references the MDB implementation. Currently, not all features of MDB were implemented.

[https://github.com/joyent/node/tree/master/deps/mdb_v8](https://github.com/joyent/node/tree/master/deps/mdb_v8)


##features implemented
0:000> !v8dbgexts.help
Help for V8DbgExts.dll
  help                  - Shows this help  
  stack					- Dump Call Stacks with JavaScript stack  
  dumpJsObj				- dump a JSObject  
  v8ver					- Get V8 Version  
  findJsObject			- Find JSObject in specified address, if no address give, search whole V8 heap  
  objType				- Given an JSObject address, print the type of object  
  dumpJsFun				- Given an JsSharedFunction object address, print the details of the function  

  


##print the jscript call stack
###The native one
0:000> kL
 # ChildEBP RetAddr  
00 0152ea24 14865af1 0x14865b2c  
01 0152ea4c 14865af1 0x14865af1  
02 0152ea74 14865b20 0x14865af1  
03 0152ea9c 14865af1 0x14865b20  
04 0152eac4 14865af1 0x14865af1  
05 0152eaec 14865af1 0x14865af1  
06 0152eb14 14865af1 0x14865af1  
07 0152eb3c 14865af1 0x14865af1  
08 0152eb64 14865af1 0x14865af1  
09 0152eb8c 14865b20 0x14865af1  
0a 0152ebb4 14865af1 0x14865b20  
0b 0152ebdc 14865af1 0x14865af1  
0c 0152ec04 14865af1 0x14865af1  
0d 0152ec2c 14865af1 0x14865af1  
0e 0152ec54 14865af1 0x14865af1  
0f 0152ec7c 14865af1 0x14865af1  
10 0152eca4 14865af1 0x14865af1  
11 0152eccc 14865af1 0x14865af1  
12 0152ecf4 14865af1 0x14865af1  
13 0152ed1c 14865af1 0x14865af1  
14 0152ed44 14865b20 0x14865af1  
15 0152ed6c 14865af1 0x14865b20  
16 0152ed94 14865af1 0x14865af1  
17 0152edbc 14865b20 0x14865af1  
18 0152ede4 14865af1 0x14865b20  
19 0152ee0c 14865b20 0x14865af1  
1a 0152ee34 14865af1 0x14865b20  
1b 0152ee5c 14865af1 0x14865af1  
1c 0152ee84 14865b20 0x14865af1  
1d 0152eeac 14865b20 0x14865b20  
1e 0152eed4 14865b20 0x14865b20   
1f 0152eefc 14865af1 0x14865b20  
20 0152ef24 14865af1 0x14865af1  
21 0152ef4c 1486589b 0x14865af1  
22 0152ef6c 1486586d 0x1486589b   
23 0152ef88 1486586d 0x1486586d  
24 0152efa4 1486586d 0x1486586d  
25 0152efc0 1486586d 0x1486586d  
26 0152efdc 1486586d 0x1486586d  
27 0152eff8 1486586d 0x1486586d  
28 0152f014 1486586d 0x1486586d  
29 0152f030 1486586d 0x1486586d  
2a 0152f04c 1486586d 0x1486586d  
2b 0152f068 1486586d 0x1486586d  
2c 0152f084 1486586d 0x1486586d  
2d 0152f0a0 1486586d 0x1486586d  
2e 0152f0bc 1486586d 0x1486586d  
2f 0152f0d8 14864c92 0x1486586d  
30 0152f0fc 1486106e 0x14864c92  
31 0152f11c 14835364 0x1486106e  
32 0152f15c 37b1e83b 0x14835364  
33 0152f178 14860452 0x37b1e83b  
34 0152f1a4 1485e7ae 0x14860452  
35 0152f1d8 37b1ed55 0x1485e7ae  
36 0152f1f8 37b1e0ca 0x37b1ed55  
37 0152f234 00c8ec6a 0x37b1e0ca  
38 0152f280 00c8ee67 node!v8::internal::Invoke+0x13a  
39 0152f2bc 00c10e92 node!v8::internal::Execution::Call+0x137  
3a 0152f300 00aebcca node!v8::Function::Call+0xf2  
3b 0152f354 00bca086 node!node::Parser::on_headers_complete_+0x41a  
3c 0152f3a0 00aec39b node!http_parser_execute+0x5c6  
3d 0152f3ec 00d466f4 node!node::Parser::Execute+0x19b  
3e 0152f420 00d12b11 node!v8::internal::FunctionCallbackArguments::Call+0x84  
3f 0152f488 00d10a94 node!v8::internal::HandleApiCallHelper<0>+0x1b1  
40 0152f498 37b0a076 node!v8::internal::Builtin_HandleApiCall+0x14  
41 0152f4b8 1485de96 0x37b0a076  
42 0152f4ec 1483530d 0x1485de96  
43 0152f528 37b1e83b 0x1483530d  
44 0152f544 1485d94b 0x37b1e83b  
45 0152f56c 1485d50b 0x1485d94b  
46 0152f59c 37b1e83b 0x1485d50b  
47 0152f5bc 1485c47e 0x37b1e83b  
48 0152f5e8 37b1e83b 0x1485c47e  
49 0152f608 37b1ed50 0x37b1e83b  
4a 0152f630 37b1e0ca 0x37b1ed50  
4b 0152f66c 00c8ec6a 0x37b1e0ca  
4c 0152f6b8 00c8ee67 node!v8::internal::Invoke+0x13a  
4d 0152f6f4 00c10e92 node!v8::internal::Execution::Call+0x137  
4e 0152f738 00ac33e2 node!v8::Function::Call+0xf2  
4f 0152f7b8 00ac3b2b node!node::AsyncWrap::MakeCallback+0x2b2  
50 0152f7dc 00afc6a6 node!node::AsyncWrap::MakeCallback+0x9b  
51 0152f828 00afada9 node!node::StreamWrapCallbacks::DoRead+0x1f6  
52 0152f850 00afadf6 node!node::StreamWrap::OnReadCommon+0x99  
53 0152f864 00be63ba node!node::StreamWrap::OnRead+0x46  
54 0152fb24 00bd8790 node!uv_process_pipe_read_req+0x30a  
55 0152fb40 00bd8ef8 node!uv_process_reqs+0x90  
56 0152fb68 00aed8be node!uv_run+0xe8  
57 0152fbb0 00f69ba5 node!wmain+0x2ee  
58 0152fbf8 77c586e3 node!__tmainCRTStartup+0xfe  
59 0152fc04 77e8be19 kernel32!BaseThreadInitThunk+0xe  
5a 0152fc48 77e8bdec ntdll!__RtlUserThreadStart+0x72  
5b 0152fc60 00000000 ntdll!_RtlUserThreadStart+0x1b  
  

###The jscript stack
This prints out both jscript and native stacks with jscript function name, file name and source code line number.

0:000> !v8dbgexts.stack
 #  ChildEBP RetAddr  Args to Child  
00 0152ea24 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
01 0152ea4c 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
02 0152ea74 14865b20 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
03 0152ea9c 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
04 0152eac4 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
05 0152eaec 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
06 0152eb14 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
07 0152eb3c 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
08 0152eb64 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
09 0152eb8c 14865b20 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
0a 0152ebb4 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
0b 0152ebdc 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
0c 0152ec04 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
0d 0152ec2c 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
0e 0152ec54 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
0f 0152ec7c 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
10 0152eca4 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
11 0152eccc 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
12 0152ecf4 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
13 0152ed1c 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
14 0152ed44 14865b20 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
15 0152ed6c 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
16 0152ed94 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
17 0152edbc 14865b20 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
18 0152ede4 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
19 0152ee0c 14865b20 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
1a 0152ee34 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
1b 0152ee5c 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
1c 0152ee84 14865b20 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
1d 0152eeac 14865b20 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
1e 0152eed4 14865b20 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
1f 0152eefc 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
20 0152ef24 14865af1 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
21 0152ef4c 1486589b fibo [D:\home\site\wwwroot\server.js @ 52 ]  
22 0152ef6c 1486586d fibo [D:\home\site\wwwroot\server.js @ 52 ]  
23 0152ef88 1486586d fibo [D:\home\site\wwwroot\server.js @ 52 ]  
24 0152efa4 1486586d fibo [D:\home\site\wwwroot\server.js @ 52 ]  
25 0152efc0 1486586d fibo [D:\home\site\wwwroot\server.js @ 52 ]  
26 0152efdc 1486586d fibo [D:\home\site\wwwroot\server.js @ 52 ]  
27 0152eff8 1486586d fibo [D:\home\site\wwwroot\server.js @ 52 ]  
28 0152f014 1486586d fibo [D:\home\site\wwwroot\server.js @ 52 ]  
29 0152f030 1486586d fibo [D:\home\site\wwwroot\server.js @ 52 ]  
2a 0152f04c 1486586d fibo [D:\home\site\wwwroot\server.js @ 52 ]  
2b 0152f068 1486586d fibo [D:\home\site\wwwroot\server.js @ 52 ]  
2c 0152f084 1486586d fibo [D:\home\site\wwwroot\server.js @ 52 ]  
2d 0152f0a0 1486586d fibo [D:\home\site\wwwroot\server.js @ 52 ]  
2e 0152f0bc 1486586d fibo [D:\home\site\wwwroot\server.js @ 52 ]  
2f 0152f0d8 14864c92 fibo [D:\home\site\wwwroot\server.js @ 52 ]  
30 0152f0fc 1486106e wzhao_execute_request [D:\home\site\wwwroot\server.js @ 29 ]  
31 0152f11c 14835364 <anounymous> [D:\home\site\wwwroot\server.js @ 165 ]  
32 0152f15c 37b1e83b emit [events.js @ 68 ]  
33 0152f178 14860452 emit [events.js @ 68 ]  
34 0152f1a4 1485e7ae parserOnIncoming [_http_server.js @ 420 ]  
35 0152f1d8 37b1ed55 parserOnHeadersComplete [_http_common.js @ 63 ]  
36 0152f1f8 37b1e0ca UNKNOWN  
37 0152f234 00c8ec6a ENTRYCONSTRUCTFRAME  
38 0152f280 00c8ee67 node!v8::internal::Invoke+0x13a  
39 0152f2bc 00c10e92 node!v8::internal::Execution::Call+0x137  
3a 0152f300 00aebcca node!v8::Function::Call+0xf2  
3b 0152f354 00bca086 node!node::Parser::on_headers_complete_+0x41a  
3c 0152f3a0 00aec39b node!http_parser_execute+0x5c6  
3d 0152f3ec 00d466f4 node!node::Parser::Execute+0x19b  
3e 0152f420 00d12b11 node!v8::internal::FunctionCallbackArguments::Call+0x84  
3f 0152f488 00d10a94 node!v8::internal::HandleApiCallHelper<0>+0x1b1  
40 0152f498 37b0a076 node!v8::internal::Builtin_HandleApiCall+0x14  
41 0152f4b8 1485de96 Internal Frame(37b0a001)  
42 0152f4ec 1483530d socketOnData [_http_server.js @ 340 ]  
43 0152f528 37b1e83b emit [events.js @ 68 ]  
44 0152f544 1485d94b emit [events.js @ 68 ]  
45 0152f56c 1485d50b readableAddChunk [_stream_readable.js @ 139 ]  
46 0152f59c 37b1e83b Readable.push [_stream_readable.js @ 115 ]  
47 0152f5bc 1485c47e Readable.push [_stream_readable.js @ 115 ]  
48 0152f5e8 37b1e83b onread [net.js @ 516 ]  
49 0152f608 37b1ed50 onread [net.js @ 516 ]  
4a 0152f630 37b1e0ca UNKNOWN  
4b 0152f66c 00c8ec6a ENTRYCONSTRUCTFRAME  
4c 0152f6b8 00c8ee67 node!v8::internal::Invoke+0x13a  
4d 0152f6f4 00c10e92 node!v8::internal::Execution::Call+0x137  
4e 0152f738 00ac33e2 node!v8::Function::Call+0xf2  
4f 0152f7b8 00ac3b2b node!node::AsyncWrap::MakeCallback+0x2b2  
50 0152f7dc 00afc6a6 node!node::AsyncWrap::MakeCallback+0x9b  
51 0152f828 00afada9 node!node::StreamWrapCallbacks::DoRead+0x1f6  
52 0152f850 00afadf6 node!node::StreamWrap::OnReadCommon+0x99  
53 0152f864 00be63ba node!node::StreamWrap::OnRead+0x46  
54 0152fb24 00bd8790 node!uv_process_pipe_read_req+0x30a  
55 0152fb40 00bd8ef8 node!uv_process_reqs+0x90  
56 0152fb68 00aed8be node!uv_run+0xe8  
57 0152fbb0 00f69ba5 node!wmain+0x2ee  
58 0152fbf8 77c586e3 node!__tmainCRTStartup+0xfe  
59 0152fc04 77e8be19 kernel32!BaseThreadInitThunk+0xe  
5a 0152fc48 77e8bdec ntdll!__RtlUserThreadStart+0x72  
5b 0152fc60 00000000 ntdll!_RtlUserThreadStart+0x1b  



##Another jscirpt stack sample  
0:000> kL  
 # ChildEBP RetAddr    
00 0111f1dc 002e0412 node!v8::internal::ElementsAccessorBase<v8::internal::FastHoleyObjectElementsAccessor,v8::internal::ElementsKindTraits<3> >::SetLengthImpl+0x43  
01 0111f1e8 002e8c66 node!v8::internal::ElementsAccessorBase<v8::internal::FastHoleySmiElementsAccessor,v8::internal::ElementsKindTraits<1> >::SetLength+0x12  
02 0111f1f8 14a0a376 node!v8::internal::StoreIC_ArrayLength+0x26  
03 0111f214 14a366ca 0x14a0a376  
04 0111f258 14a363e4 0x14a366ca  
05 0111f280 2682ae58 0x14a363e4  
06 0111f320 14a0e501 0x2682ae58  
07 0111f338 26829069 0x14a0e501  
08 0111f35c 26821a21 0x26829069  
09 0111f37c 2682159b 0x26821a21  
0a 0111f3a4 14a0e501 0x2682159b  
0b 0111f3cc 2682a0be 0x14a0e501  
0c 0111f410 26820569 0x2682a0be  
0d 0111f428 2681cf5b 0x26820569  
0e 0111f448 2681325c 0x2681cf5b  
0f 0111f484 14a0e501 0x2681325c  
10 0111f4a0 2681c510 0x14a0e501  
11 0111f4c4 2681adb3 0x2681c510  
12 0111f500 14a21899 0x2681adb3  
13 0111f520 14a1308a 0x14a21899  
14 0111f55c 0022c1ae 0x14a1308a  
15 0111f5ac 0022c4eb node!v8::internal::Invoke+0xee  
16 0111f5ec 001e9b7a node!v8::internal::Execution::Call+0x17b  
17 0111f638 000e2798 node!v8::Function::Call+0x15a  
18 0111f66c 000e24dd node!node::Parser::on_headers_complete_+0x2b8  
19 0111f674 001b5365 node!node::Parser::on_headers_complete+0xd  
1a 0111f6a8 000e2fb5 node!http_parser_execute+0x205  
1b 0111f720 00297ae4 node!node::Parser::Execute+0x355  
1c 0111f788 00295de6 node!v8::internal::HandleApiCallHelper<0>+0x1e4  
1d 0111f798 14a0a376 node!v8::internal::Builtin_HandleApiCall+0x16  
1e 0111f7b4 2681a66a 0x14a0a376  
1f 0111f7ec 26819f1b 0x2681a66a  
20 0111f820 14a21899 0x26819f1b  
21 0111f848 14a1308a 0x14a21899  
22 0111f884 0022c1ae 0x14a1308a  
23 0111f8d4 0022c4eb node!v8::internal::Invoke+0xee  
24 0111f914 001e9b7a node!v8::internal::Execution::Call+0x17b  
25 0111f960 000c966b node!v8::Function::Call+0x15a  
26 0111f99c 000c9773 node!node::MakeCallback+0xcb  
27 0111f9dc 000ed6e1 node!node::MakeCallback+0x53  
28 0111fa44 000ed71d node!node::StreamWrap::OnReadCommon+0x2b1  
29 0111fa60 001d5213 node!node::StreamWrap::OnRead+0x1d  
2a 0111fa94 001be461 node!uv_process_tcp_read_req+0x1c3  
2b 0111fab4 001beaed node!uv_process_reqs+0x91  
2c 0111fad0 000e448c node!uv_run+0xbd  
2d 0111fb1c 003d1bd4 node!wmain+0x19c  
2e 0111fb64 74c08624 node!__tmainCRTStartup+0x10b  
2f 0111fb70 7764bf39 KERNEL32!BaseThreadInitThunk+0xe  
30 0111fbb4 7764bf0c ntdll!__RtlUserThreadStart+0x72  
31 0111fbcc 00000000 ntdll!_RtlUserThreadStart+0x1b  

0:000> !v8dbgexts.stack  
 #  ChildEBP RetAddr  Args to Child  
00 0111f1dc 002e0412 node!v8::internal::ElementsAccessorBase<v8::internal::FastHoleyObjectElementsAccessor,v8::internal::ElementsKindTraits<3> >::SetLengthImpl+0x43  
01 0111f1e8 002e8c66 node!v8::internal::ElementsAccessorBase<v8::internal::FastHoleySmiElementsAccessor,v8::internal::ElementsKindTraits<1> >::SetLength+0x12  
02 0111f1f8 14a0a376 node!v8::internal::StoreIC_ArrayLength+0x26  
03 0111f214 14a366ca undefined [ ]  
04 0111f258 14a363e4 Join [native array.js ]  
05 0111f280 2682ae58 join [native array.js ]  
06 0111f320 14a0e501 exports.resolve [path.js @ 89 ]  
07 0111f338 26829069 exports.resolve [path.js @ 89 ]  
08 0111f35c 26821a21 exports._makeLong [path.js @ 460 ]  
09 0111f37c 2682159b fs.open [fs.js @ 424 ]  
0a 0111f3a4 14a0e501 fs.writeFile [fs.js @ 937 ]  
0b 0111f3cc 2682a0be fs.writeFile [fs.js @ 937 ]  
0c 0111f410 26820569 fileASyncTest [D:\TestCode\NodeDebugger\server.js @ 20 ]  
0d 0111f428 2681cf5b wzhao_execute_request [D:\TestCode\NodeDebugger\server.js @ 29 ]  
0e 0111f448 2681325c <anounymous> [D:\TestCode\NodeDebugger\server.js @ 164 ]  
0f 0111f484 14a0e501 emit [events.js @ 53 ]  
10 0111f4a0 2681c510 emit [events.js @ 53 ]  
11 0111f4c4 2681adb3 parser.onIncoming [http.js @ 2042 ]  
12 0111f500 14a21899 parserOnHeadersComplete [http.js @ 69 ]  
13 0111f520 14a1308a ??  
14 0111f55c 0022c1ae ??  
15 0111f5ac 0022c4eb node!v8::internal::Invoke+0xee  
16 0111f5ec 001e9b7a node!v8::internal::Execution::Call+0x17b  
17 0111f638 000e2798 node!v8::Function::Call+0x15a  
18 0111f66c 000e24dd node!node::Parser::on_headers_complete_+0x2b8  
19 0111f674 001b5365 node!node::Parser::on_headers_complete+0xd  
1a 0111f6a8 000e2fb5 node!http_parser_execute+0x205  
1b 0111f720 00297ae4 node!node::Parser::Execute+0x355  
1c 0111f788 00295de6 node!v8::internal::HandleApiCallHelper<0>+0x1e4  
1d 0111f798 14a0a376 node!v8::internal::Builtin_HandleApiCall+0x16  
1e 0111f7b4 2681a66a undefined [ ]  
1f 0111f7ec 26819f1b socket.ondata [http.js @ 1968 ]  
20 0111f820 14a21899 onread [net.js @ 496 ]  
21 0111f848 14a1308a ??  
22 0111f884 0022c1ae ??  
23 0111f8d4 0022c4eb node!v8::internal::Invoke+0xee  
24 0111f914 001e9b7a node!v8::internal::Execution::Call+0x17b  
25 0111f960 000c966b node!v8::Function::Call+0x15a  
26 0111f99c 000c9773 node!node::MakeCallback+0xcb  
27 0111f9dc 000ed6e1 node!node::MakeCallback+0x53  
28 0111fa44 000ed71d node!node::StreamWrap::OnReadCommon+0x2b1  
29 0111fa60 001d5213 node!node::StreamWrap::OnRead+0x1d  
2a 0111fa94 001be461 node!uv_process_tcp_read_req+0x1c3  
2b 0111fab4 001beaed node!uv_process_reqs+0x91  
2c 0111fad0 000e448c node!uv_run+0xbd  
2d 0111fb1c 003d1bd4 node!wmain+0x19c  
2e 0111fb64 74c08624 node!__tmainCRTStartup+0x10b  
2f 0111fb70 7764bf39 KERNEL32!BaseThreadInitThunk+0xe  
30 0111fbb4 7764bf0c ntdll!__RtlUserThreadStart+0x72  
31 0111fbcc 00000000 ntdll!_RtlUserThreadStart+0x1b  



##jscript source
0:000> !v8dbgexts.dumpJsFun 26b30114  
Function : fibo  
File Name : D:\home\site\wwwroot\server.js @ 52  
function fibo(n) {  
  return n == 0 ? 0 :  
         n == 1 ? 1 :  
         fibo(n-1) + fibo(n-2);  
}  




##JSObject type
0:000> !objType 26b30114  
Object @ 26b30114 type=b6 ( SHARED_FUNCTION_INFO_TYPE )  
 
0:000> !objType 26a29bf8   
Object @ 26a29bf8 type=4 ( ASCIISTRING ) 




#V8 version
0:000> !v8ver  
V8 Version: 3.28.71.19
