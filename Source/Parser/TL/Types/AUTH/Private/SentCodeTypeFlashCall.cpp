#include "../Public/SentCodeTypeFlashCall.h"


//begin namespace block
namespace AUTH
{

SentCodeTypeFlashCall::SentCodeTypeFlashCall()
{
	this->_ConstructorID = -1425815847;
}

SentCodeTypeFlashCall::SentCodeTypeFlashCall(FString pattern)
{
	this->_ConstructorID = -1425815847;
	this->pattern = pattern;
}
void SentCodeTypeFlashCall::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->pattern);
}


void SentCodeTypeFlashCall::OnResponce(BinaryReader& Reader)
{
	pattern = Reader.TGReadString();
	this->_Responded = true;
}
SentCodeTypeFlashCall::~SentCodeTypeFlashCall()
{

}
}//end namespace block
