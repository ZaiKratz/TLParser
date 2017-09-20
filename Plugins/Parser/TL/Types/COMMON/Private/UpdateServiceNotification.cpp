#include "../Public/UpdateServiceNotification.h"


//begin namespace block
namespace COMMON
{

UpdateServiceNotification::UpdateServiceNotification()
{
	this->_ConstructorID = 426304747;
}

UpdateServiceNotification::UpdateServiceNotification(bool popup, FDateTime inbox_date, FString type, FString message, PRIVATE::MessageMedia* media, TArray<PRIVATE::MessageEntity*> entities)
{
	this->_ConstructorID = 426304747;
	this->popup = popup;
	this->inbox_date = inbox_date;
	this->type = type;
	this->message = message;
	this->media = media;
	this->entities = entities;
}
void UpdateServiceNotification::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!popup)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!inbox_date.ToString().IsEmpty())
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	if(!inbox_date.ToString().IsEmpty())
	{
	Writer.TGWriteDate(this->inbox_date);
	}
	Writer.TGWriteString(this->type);
	Writer.TGWriteString(this->message);
	this->media->OnSend(Writer);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->entities.Num());
	for(auto X : this->entities)
	{
	X->OnSend(Writer);
	}
}


void UpdateServiceNotification::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		popup = true;
	}
	if((Flags & (1 << 1)) != 0) 
	{
	inbox_date = Reader.TGReadDate();
	}
	type = Reader.TGReadString();
	message = Reader.TGReadString();
	media = reinterpret_cast<PRIVATE::MessageMedia*>(Reader.TGReadObject());
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len5475 = Reader.ReadInt();
	for(int32 i = 0; i < Len5475; i++)
	{
	auto X = reinterpret_cast<PRIVATE::MessageEntity*>(Reader.TGReadObject());
	entities.Add(X);
	}
}
UpdateServiceNotification::~UpdateServiceNotification()
{

}
}//end namespace block
