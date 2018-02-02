// ICReader.cpp : CICReader 的实现

#include "stdafx.h"
#include "ICReader.h"
#include <string>
#include <vector>
#include <comdef.h>
#include <atltime.h>



// CICReader
STDMETHODIMP CICReader::TestICCard(LONG* ReturnCode)
{
	// TODO:  在此添加实现代码
	
	return S_OK;
}

//判卡
STDMETHODIMP CICReader::isOurCard(LONG* isFlag)
{
	// TODO:  在此添加实现代码
	if (this->hInstLibrary == NULL)
		*isFlag = 2000;
	else if (this->_isOurCard == NULL)
		*isFlag = 1000;
	else
		*isFlag = this->_isOurCard(this->port, this->baud);
			
	return S_OK;
}

//读卡
STDMETHODIMP CICReader::ReadCard(BSTR* readinfo)
{
	// TODO:  在此添加实现代码
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

//解析前端传递的参数字符串
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

//制用户卡
STDMETHODIMP CICReader::WriteUserCard(BSTR param, LONG* returncode)
{
	// TODO:  在此添加实现代码
	_bstr_t bstrParam(param);
	std::string src(bstrParam);
	std::string seperator = ";";
	std::vector<std::string> vctParam;

	//解析前端传递的参数字符串
	seperateString(src, ";", vctParam);

	//设置参数
	std::string strUserID = vctParam.at(0);
	_bstr_t bstrKey(this->key);
	std::string strKey(bstrKey);
	int m_nOverdrafft = std::stoi(vctParam.at(1), 0, 10);  //透支
	int m_nMax = std::stoi(vctParam.at(2), 0, 10);  //最大储气量
	int m_nDay1 = std::stoi(vctParam.at(3), 0, 10);  //防死表1
	int m_nDay2 = std::stoi(vctParam.at(4), 0, 10);   //防死表2
	int m_nYears = std::stoi(vctParam.at(5), 0, 10);  //使用年限
	int m_nAlarm = std::stoi(vctParam.at(6), 0, 10);  //报警气量
	double m_dGas = 0; //购气量
	int m_nBukaTimes = 0; //补卡次数
	int m_nBuyTimes = 0;  //购气次数

	char paramTemp[100] = { 0 };
	sprintf_s(paramTemp, "%d;%d;%d;%d;%d;%d;", m_nOverdrafft, m_nMax, m_nDay1, m_nDay2, m_nYears, m_nAlarm);
	*returncode = this->_WriteUserCard(this->port, this->baud, (unsigned char*)strKey.c_str(), (char*)strUserID.c_str(), paramTemp, m_dGas, m_nBukaTimes, m_nBuyTimes, flag);
	return S_OK;
}

//还原卡
STDMETHODIMP CICReader::CleanCard(LONG* returncode)
{
	// TODO:  在此添加实现代码
	*returncode = this->_CleanCard(this->port, this->baud);
	return S_OK;
}

//购气
STDMETHODIMP CICReader::BuyGas(DOUBLE gas, BSTR userid, SHORT buytimes, LONG* returncode)
{
	// TODO:  在此添加实现代码
	CTime timer = CTime::GetCurrentTime();
	CString nowtime = timer.Format(L"%Y%m%d");
	_bstr_t bstrUserId(userid);
	std::string strUserId(bstrUserId);
	USES_CONVERSION;
	*returncode = this->_BuyGas(this->port, this->baud, gas, T2A(nowtime), buytimes, (char*)strUserId.c_str());
	return S_OK;
}



//测试加法
STDMETHODIMP CICReader::add(LONG arg1, LONG arg2, SHORT* result)
{
	
	// TODO:  在此添加实现代码
	*result = arg1+arg2;
	return S_OK;
}

