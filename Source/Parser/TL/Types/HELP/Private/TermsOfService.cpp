#include "../Public/TermsOfService.h"


//begin namespace block
namespace HELP
{

TermsOfService::TermsOfService()
{
	this->_ConstructorID = -236044656;
}

TermsOfService::TermsOfService(FString text)
{
	this->_ConstructorID = -236044656;
	this->text = text;
}
void TermsOfService::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->text);
}


void TermsOfService::OnResponce(BinaryReader& Reader)
{
	text = Reader.TGReadString();
	this->_Responded = true;
}
TermsOfService::~TermsOfService()
{

}
}//end namespace block
