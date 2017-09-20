#include "../Public/RpcError.h"


//begin namespace block
namespace COMMON
{

RpcError::RpcError()
{
	this->_ConstructorID = 432686113;
}

RpcError::RpcError(int32 error_code, FString error_message)
{
	this->_ConstructorID = 432686113;
	this->error_code = error_code;
	this->error_message = error_message;
}
void RpcError::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->error_code);
	Writer.TGWriteString(this->error_message);
}


void RpcError::OnResponce(BinaryReader& Reader)
{
	error_code = Reader.ReadInt();
	error_message = Reader.TGReadString();
}
RpcError::~RpcError()
{

}
}//end namespace block
