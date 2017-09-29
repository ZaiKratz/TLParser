#include "../Public/DropTempAuthKeys.h"


//begin namespace block
namespace AUTH
{

DropTempAuthKeys::DropTempAuthKeys()
{
	this->_ConstructorID = -1907842680;
	this->_ContentRelated = true;
}

DropTempAuthKeys::DropTempAuthKeys(TArray<unsigned long long>  except_auth_keys)
{
	this->_ConstructorID = -1907842680;
	this->_ContentRelated = true;
	this->except_auth_keys = except_auth_keys;
}
void DropTempAuthKeys::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->except_auth_keys.Num());
	for(auto X : this->except_auth_keys)
	{
	Writer.WriteLong(X);
	}
}


void DropTempAuthKeys::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
DropTempAuthKeys::~DropTempAuthKeys()
{

}
}//end namespace block
