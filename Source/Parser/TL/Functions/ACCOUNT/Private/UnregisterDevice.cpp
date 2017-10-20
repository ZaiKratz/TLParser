#include "../Public/UnregisterDevice.h"


//begin namespace block
namespace ACCOUNT
{

UnregisterDevice::UnregisterDevice()
{
	this->_ConstructorID = 1707432768;
	this->_ContentRelated = true;
}

UnregisterDevice::UnregisterDevice(int32 token_type, FString token)
{
	this->_ConstructorID = 1707432768;
	this->_ContentRelated = true;
	this->token_type = token_type;
	this->token = token;
}
void UnregisterDevice::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->token_type);
	Writer.TGWriteString(this->token);
}


void UnregisterDevice::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
UnregisterDevice::~UnregisterDevice()
{
}
}//end namespace block
