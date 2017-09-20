#include "../Public/TermsOfService.h"


//begin namespace block
namespace HELP
{

TermsOfService::TermsOfService()
{
	this->_ConstructorID = -1874923791;
}

TermsOfService::TermsOfService(FString text)
{
	this->_ConstructorID = -1874923791;
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
}
TermsOfService::~TermsOfService()
{

}
}//end namespace block
