#include "../Public/InputMediaPhoto.h"


//begin namespace block
namespace COMMON
{

InputMediaPhoto::InputMediaPhoto()
{
	this->_ConstructorID = 976747137;
}

InputMediaPhoto::InputMediaPhoto(COMMON::InputPhoto* id, FString caption, int32 ttl_seconds)
{
	this->_ConstructorID = 976747137;
	this->id = id;
	this->caption = caption;
	this->ttl_seconds = ttl_seconds;
}
void InputMediaPhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!ttl_seconds)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->id->OnSend(Writer);
	Writer.TGWriteString(this->caption);
	if(!this->ttl_seconds)
	{
	Writer.WriteInt(this->ttl_seconds);
	}
}


void InputMediaPhoto::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	id = reinterpret_cast<COMMON::InputPhoto*>(Reader.TGReadObject());
	caption = Reader.TGReadString();
	if((Flags & (1 << 0)) != 0) 
	{
	ttl_seconds = Reader.ReadInt();
	}
}
InputMediaPhoto::~InputMediaPhoto()
{

}
}//end namespace block
