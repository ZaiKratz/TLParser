#include "../Public/SendCustomRequest.h"


//begin namespace block
namespace BOTS
{

SendCustomRequest::SendCustomRequest()
{
	this->_ConstructorID = -1440257555;
	this->_ContentRelated = true;
}

SendCustomRequest::SendCustomRequest(FString custom_method, COMMON::DataJSON*  params)
{
	this->_ConstructorID = -1440257555;
	this->_ContentRelated = true;
	this->custom_method = custom_method;
	this->params = params;
}
void SendCustomRequest::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->custom_method);
	this->params->OnSend(Writer);
}


void SendCustomRequest::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::DataJSON*>(Reader.TGReadObject());
	this->_Responded = true;
}
SendCustomRequest::~SendCustomRequest()
{

}
}//end namespace block
