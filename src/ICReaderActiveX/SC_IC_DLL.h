// #ifdef DLL1_API
// #else
// #define DLL1_API extern"C"_declspec(dllimport)
// #endif

int __stdcall WriteUserCard(short Port, int Baud, unsigned char Key[2], char* UserID, char* SetInfo, double gas, int RenewTimes, int BuyTimes, const short SetFlag);
int __stdcall BuyGas(short Port, int Baud, double gas, char* BuyDate, short buyTimes, char* UserID);
int __stdcall CleanCard(short Port, int Baud);
int __stdcall ReadCard(short Port, int Baud, char* CardInfo, char* SetInfo);
int __stdcall WriteFunctionCard(short Port, int Baud, int CardKind, unsigned char Key[2], double TestGasNum = 0.0);
int __stdcall ModifySet(short Port, int Baud, char* SetInfo, short SetFlag);
int __stdcall IsOurCard(short Port,int Baud);
int __stdcall CleanGas(short Port,int Baud, double fGas);
/*
动态库返回值
	1. 串口打开失败
	2. 未插卡
	3. 密码校验失败
	4. 非法卡
	5. 读卡失败
	6. 写卡失败
	7. 改密码失败
	8. 数据校验错误
	9. 卡内有值
	10. 退气数据不对
	11.设置参数格式有误
	12.卡坏
	13.新卡
	14.工具卡
	15.购气次数错误
	16.用户ID不一致

CardKind
1://测试卡
2://关阀卡
3://开阀卡
4://恢复卡(清零卡)


SETINFO:
0.透支(方)
1.最大储气量(方)
2.防死表1(天)
3.防死表2(天)
4.年限(年)
5.报警气量(方)
6.SETFlag


CardInfo:
编号
总用气量
剩余气量
错误代码
平均流量
最大流量
购气日期
卡内气量
补卡次数
购气次数
上表次数

*/


