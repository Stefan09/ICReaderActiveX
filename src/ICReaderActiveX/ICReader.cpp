// ICReader.cpp : CICReader ��ʵ��

#include "stdafx.h"
#include "ICReader.h"
#include <string>
#include <vector>
#include <comdef.h>
#include <atltime.h>



// CICReader
STDMETHODIMP CICReader::TestICCard(LONG* ReturnCode)
{
	// TODO:  �ڴ����ʵ�ִ���
	
	return S_OK;
}

//�п�
STDMETHODIMP CICReader::isOurCard(LONG* isFlag)
{
	// TODO:  �ڴ����ʵ�ִ���
	if (this->hInstLibrary == NULL)
		*isFlag = 2000;
	else if (this->_isOurCard == NULL)
		*isFlag = 1000;
	else
		*isFlag = this->_isOurCard(this->port, this->baud);
			
	return S_OK;
}

//����
STDMETHODIMP CICReader::ReadCard(BSTR* readinfo)
{
	// TODO:  �ڴ����ʵ�ִ���
	char cardInfo[100] = { 0 };
	char setInfo[100] = { 0 };
	this->_ReadCard(this->port, this->baud, cardInfo, setInfo);
	std::string strCardInfo(cardInfo);
	std::string strSetInfo(setInfo);
	strCardInfo.append(strSetInfo);
	_bstr_t bstrReturnInfo(strCardInfo.c_str());
	*readinfo = bstrReturnInfo;
	return S_OK;
}

//����ǰ�˴��ݵĲ����ַ���
void seperateString(std::string &src, const std::string seperator, std::vector<std::string> &dest)
{
	std::string::size_type start, end;
	std::string subString;

	for (start = 0, end = src.find_first_of(seperator, start); end != std::string::npos;)
	{
		subString = src.substr(start, end - start);
		dest.push_back(subString);
		start = end + 1;
		end = src.find_first_of(seperator, start);
	}
}

//���û���
STDMETHODIMP CICReader::WriteUserCard(BSTR param, LONG* returncode)
{
	// TODO:  �ڴ����ʵ�ִ���
	_bstr_t bstrParam(param);
	std::string src(bstrParam);
	std::string seperator = ";";
	std::vector<std::string> vctParam;

	//����ǰ�˴��ݵĲ����ַ���
	seperateString(src, ";", vctParam);

	//���ò���
	std::string strUserID = vctParam.at(0);
	_bstr_t bstrKey(this->key);
	std::string strKey(bstrKey);
	int m_nOverdrafft = std::stoi(vctParam.at(1), 0, 10);  //͸֧
	int m_nMax = std::stoi(vctParam.at(2), 0, 10);  //�������
	int m_nDay1 = std::stoi(vctParam.at(3), 0, 10);  //������1
	int m_nDay2 = std::stoi(vctParam.at(4), 0, 10);   //������2
	int m_nYears = std::stoi(vctParam.at(5), 0, 10);  //ʹ������
	int m_nAlarm = std::stoi(vctParam.at(6), 0, 10);  //��������
	double m_dGas = 0; //������
	int m_nBukaTimes = 0; //��������
	int m_nBuyTimes = 0;  //��������

	char paramTemp[100] = { 0 };
	sprintf_s(paramTemp, "%d;%d;%d;%d;%d;%d;", m_nOverdrafft, m_nMax, m_nDay1, m_nDay2, m_nYears, m_nAlarm);
	*returncode = this->_WriteUserCard(this->port, this->baud, (unsigned char*)strKey.c_str(), (char*)strUserID.c_str(), paramTemp, m_dGas, m_nBukaTimes, m_nBuyTimes, flag);
	return S_OK;
}

//��ԭ��
STDMETHODIMP CICReader::CleanCard(LONG* returncode)
{
	// TODO:  �ڴ����ʵ�ִ���
	*returncode = this->_CleanCard(this->port, this->baud);
	return S_OK;
}

//����
STDMETHODIMP CICReader::BuyGas(DOUBLE gas, BSTR userid, SHORT buytimes, LONG* returncode)
{
	// TODO:  �ڴ����ʵ�ִ���
	CTime timer = CTime::GetCurrentTime();
	CString nowtime = timer.Format(L"%Y%m%d");
	_bstr_t bstrUserId(userid);
	std::string strUserId(bstrUserId);
	USES_CONVERSION;
	*returncode = this->_BuyGas(this->port, this->baud, gas, T2A(nowtime), buytimes, (char*)strUserId.c_str());
	return S_OK;
}



//���Լӷ�
STDMETHODIMP CICReader::add(LONG arg1, LONG arg2, SHORT* result)
{
	
	// TODO:  �ڴ����ʵ�ִ���
	*result = arg1+arg2;
	return S_OK;
}

