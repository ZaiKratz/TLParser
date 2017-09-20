#include "../Public/MessageEntityPre.h"


//begin namespace block
namespace COMMON
{

MessageEntityPre::MessageEntityPre()
{
	this->_ConstructorID = -531918221;
}

MessageEntityPre::MessageEntityPre(int32 offset, int32 length, FString language)
{
	this->_ConstructorID = -531918221;
	this->offset = offset;
	this->length = length;
	this->language = language;
}
void MessageEntityPre::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->offset);
	Writer.WriteInt(this->length);
	Writer.TGWriteString(this->language);
}


void MessageEntityPre::OnResponce(BinaryReader& Reader)
{
	offset = Reader.ReadInt();
	length = Reader.ReadInt();
	language = Reader.TGReadString();
}
MessageEntityPre::~MessageEntityPre()
{

}
}//end namespace block
