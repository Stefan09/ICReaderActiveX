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
��̬�ⷵ��ֵ
	1. ���ڴ�ʧ��
	2. δ�忨
	3. ����У��ʧ��
	4. �Ƿ���
	5. ����ʧ��
	6. д��ʧ��
	7. ������ʧ��
	8. ����У�����
	9. ������ֵ
	10. �������ݲ���
	11.���ò�����ʽ����
	12.����
	13.�¿�
	14.���߿�
	15.������������
	16.�û�ID��һ��

CardKind
1://���Կ�
2://�ط���
3://������
4://�ָ���(���㿨)


SETINFO:
0.͸֧(��)
1.�������(��)
2.������1(��)
3.������2(��)
4.����(��)
5.��������(��)
6.SETFlag


CardInfo:
���
��������
ʣ������
�������
ƽ������
�������
��������
��������
��������
��������
�ϱ����

*/


