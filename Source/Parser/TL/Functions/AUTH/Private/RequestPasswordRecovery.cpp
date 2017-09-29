#include "../Public/RequestPasswordRecovery.h"


//begin namespace block
namespace AUTH
{

RequestPasswordRecovery::RequestPasswordRecovery()
{
	this->_ConstructorID = -661144474;
	this->_ContentRelated = true;
}
void RequestPasswordRecovery::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void RequestPasswordRecovery::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<AUTH::PasswordRecovery*>(Reader.TGReadObject());
	this->_Responded = true;
}
RequestPasswordRecovery::~RequestPasswordRecovery()
{

}
}//end namespace block
