#include "../Public/ChatForbidden.h"


//begin namespace block
namespace COMMON
{

ChatForbidden::ChatForbidden()
{
	this->_ConstructorID = 64;
}

ChatForbidden::ChatForbidden(int32 id, FString title)
{
	this->_ConstructorID = 64;
	this->id = id;
	this->title = title;
}
void ChatForbidden::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->id);
	Writer.TGWriteString(this->title);
}


void ChatForbidden::OnResponce(BinaryReader& Reader)
{
	id = Reader.ReadInt();
	title = Reader.TGReadString();
}
ChatForbidden::~ChatForbidden()
{

}
}//end namespace block
