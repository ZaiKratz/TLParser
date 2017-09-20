#include "../Public/SentCodeTypeFlashCall.h"


//begin namespace block
namespace AUTH
{

SentCodeTypeFlashCall::SentCodeTypeFlashCall()
{
	this->_ConstructorID = -641334357;
}

SentCodeTypeFlashCall::SentCodeTypeFlashCall(FString pattern)
{
	this->_ConstructorID = -641334357;
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
}
SentCodeTypeFlashCall::~SentCodeTypeFlashCall()
{

}
}//end namespace block
