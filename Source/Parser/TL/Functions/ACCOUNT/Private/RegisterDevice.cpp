#include "../Public/RegisterDevice.h"


//begin namespace block
namespace ACCOUNT
{

RegisterDevice::RegisterDevice()
{
	this->_ConstructorID = 1669245048;
	this->_ContentRelated = true;
}

RegisterDevice::RegisterDevice(int32 token_type, FString token)
{
	this->_ConstructorID = 1669245048;
	this->_ContentRelated = true;
	this->token_type = token_type;
	this->token = token;
}
void RegisterDevice::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->token_type);
	Writer.TGWriteString(this->token);
}


void RegisterDevice::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
RegisterDevice::~RegisterDevice()
{
}
}//end namespace block
