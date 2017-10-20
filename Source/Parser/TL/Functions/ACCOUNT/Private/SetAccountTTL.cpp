#include "../Public/SetAccountTTL.h"


//begin namespace block
namespace ACCOUNT
{

SetAccountTTL::SetAccountTTL()
{
	this->_ConstructorID = 608323678;
	this->_ContentRelated = true;
}

SetAccountTTL::SetAccountTTL(COMMON::AccountDaysTTL*  ttl)
{
	this->_ConstructorID = 608323678;
	this->_ContentRelated = true;
	this->ttl = ttl;
}
void SetAccountTTL::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->ttl->OnSend(Writer);
}


void SetAccountTTL::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
SetAccountTTL::~SetAccountTTL()
{
	if(this->ttl)
	{
		delete this->ttl;
	}
}
}//end namespace block
