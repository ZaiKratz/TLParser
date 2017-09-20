#include "../Public/ChatInviteExported.h"


//begin namespace block
namespace COMMON
{

ChatInviteExported::ChatInviteExported()
{
	this->_ConstructorID = -1140510980;
}

ChatInviteExported::ChatInviteExported(FString link)
{
	this->_ConstructorID = -1140510980;
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
}
ChatInviteExported::~ChatInviteExported()
{

}
}//end namespace block
