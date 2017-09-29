#include "../Public/InviteText.h"


//begin namespace block
namespace HELP
{

InviteText::InviteText()
{
	this->_ConstructorID = 415997816;
}

InviteText::InviteText(FString message)
{
	this->_ConstructorID = 415997816;
	this->message = message;
}
void InviteText::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->message);
}


void InviteText::OnResponce(BinaryReader& Reader)
{
	message = Reader.TGReadString();
	this->_Responded = true;
}
InviteText::~InviteText()
{

}
}//end namespace block
