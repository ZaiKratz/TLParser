#include "../Public/MessageMediaPhoto.h"


//begin namespace block
namespace COMMON
{

MessageMediaPhoto::MessageMediaPhoto()
{
	this->_ConstructorID = -1256047857;
}

MessageMediaPhoto::MessageMediaPhoto(COMMON::Photo*  photo, FString caption, int32 ttl_seconds)
{
	this->_ConstructorID = -1256047857;
	this->photo = photo;
	this->caption = caption;
	this->ttl_seconds = ttl_seconds;
}
void MessageMediaPhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(photo)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!caption.IsEmpty())
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(ttl_seconds)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	if(!this->photo)
	{
	this->photo->OnSend(Writer);
	}
	Writer.TGWriteString(this->caption);
	if(!this->ttl_seconds)
	{
	Writer.WriteInt(this->ttl_seconds);
	}
}


void MessageMediaPhoto::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
	photo = reinterpret_cast<COMMON::Photo* >(Reader.TGReadObject());
	}
	if((Flags & (1 << 1)) != 0) 
	{
	caption = Reader.TGReadString();
	}
	if((Flags & (1 << 2)) != 0) 
	{
	ttl_seconds = Reader.ReadInt();
	}
	this->_Responded = true;
}
MessageMediaPhoto::~MessageMediaPhoto()
{

}
}//end namespace block
