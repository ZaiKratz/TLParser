#include "../Public/GetInviteText.h"


//begin namespace block
namespace HELP
{

GetInviteText::GetInviteText()
{
	this->_ConstructorID = 1126381901;
	this->_ContentRelated = true;
}
void GetInviteText::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetInviteText::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<HELP::InviteText*>(Reader.TGReadObject());
}
GetInviteText::~GetInviteText()
{

}
}//end namespace block
