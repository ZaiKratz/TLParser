#include "../Public/ChatInvite.h"


//begin namespace block
namespace COMMON
{

ChatInvite::ChatInvite()
{
	this->_ConstructorID = 1492481243;
}

ChatInvite::ChatInvite(bool channel, bool broadcast, bool Public, bool megagroup, FString title, COMMON::ChatPhoto* photo, int32 participants_count, TArray<COMMON::User*> participants)
{
	this->_ConstructorID = 1492481243;
	this->channel = channel;
	this->broadcast = broadcast;
	this->Public = Public;
	this->megagroup = megagroup;
	this->title = title;
	this->photo = photo;
	this->participants_count = participants_count;
	this->participants = participants;
}
void ChatInvite::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!channel)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!broadcast)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!Public)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	if(!megagroup)
	{
		Flags |= (1 << 3);
	}
	else
	{
		Flags |= 0;
	}
	if(participants.Num())
	{
		Flags |= (1 << 4);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteString(this->title);
	this->photo->OnSend(Writer);
	Writer.WriteInt(this->participants_count);
	if(this->participants.Num())
	{
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->participants.Num());
	for(auto X : this->participants)
	{
	if(!X)
	{
	X->OnSend(Writer);
	}
	}
	}
}


void ChatInvite::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		channel = true;
	}
	if((Flags & (1 << 1)) != 0) 
	{
		broadcast = true;
	}
	if((Flags & (1 << 2)) != 0) 
	{
		Public = true;
	}
	if((Flags & (1 << 3)) != 0) 
	{
		megagroup = true;
	}
	title = Reader.TGReadString();
	photo = reinterpret_cast<COMMON::ChatPhoto*>(Reader.TGReadObject());
	participants_count = Reader.ReadInt();
	if((Flags & (1 << 4)) != 0) 
	{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len9814 = Reader.ReadInt();
	for(int32 i = 0; i < Len9814; i++)
	{
	auto X = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
	participants.Add(X);
	}
	}
}
ChatInvite::~ChatInvite()
{

}
}//end namespace block
