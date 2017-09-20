#include "TLObjectBase.h"

void TLBaseObject::OnSendSuccess()
{
	this->_SendTime = FDateTime::Now();
	this->_Sent = true;
}

void TLBaseObject::OnConfirm()
{
	this->_ConfirmReceived = true;
}

bool TLBaseObject::NeedResend()
{
	return _Dirty || (_ContentRelated && !_ConfirmReceived && ((FDateTime::Now() - _SendTime) > FApp::GetDeltaTime()));
}
