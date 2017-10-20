#include "../Public/ChatInviteExported.h"


//begin namespace block
namespace COMMON
{

ChatInviteExported::ChatInviteExported()
{
	this->_ConstructorID = -64092740;
}

ChatInviteExported::ChatInviteExported(FString link)
{
	this->_ConstructorID = -64092740;
	this->link = link;
}
void ChatInviteExported::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->link);
}


void ChatInviteExported::OnResponce(BinaryReader& Reader)
{
	link = Reader.TGReadString();
	this->_Responded = true;
}
ChatInviteExported::~ChatInviteExported()
{
}
}//end namespace block
