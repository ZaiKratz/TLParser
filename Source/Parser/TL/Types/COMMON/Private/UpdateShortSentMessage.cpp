#include "../Public/UpdateShortSentMessage.h"


//begin namespace block
namespace COMMON
{

UpdateShortSentMessage::UpdateShortSentMessage()
{
	this->_ConstructorID = 301019932;
}

UpdateShortSentMessage::UpdateShortSentMessage(bool out, int32 id, int32 pts, int32 pts_count, FDateTime date, PRIVATE::MessageMedia*  media, TArray<PRIVATE::MessageEntity*>  entities)
{
	this->_ConstructorID = 301019932;
	this->out = out;
	this->id = id;
	this->pts = pts;
	this->pts_count = pts_count;
	this->date = date;
	this->media = media;
	this->entities = entities;
}
void UpdateShortSentMessage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(out)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(media)
	{
		Flags |= (1 << 9);
	}
	else
	{
		Flags |= 0;
	}
	if(entities.Num())
	{
		Flags |= (1 << 7);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->id);
	Writer.WriteInt(this->pts);
	Writer.WriteInt(this->pts_count);
	Writer.TGWriteDate(this->date);
	if(!this->media)
	{
	this->media->OnSend(Writer);
	}
	if(this->entities.Num())
	{
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->entities.Num());
	for(auto X : this->entities)
	{
	if(!X)
	{
	X->OnSend(Writer);
	}
	}
	}
}


void UpdateShortSentMessage::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 1)) != 0) 
	{
		out = true;
	}
	id = Reader.ReadInt();
	pts = Reader.ReadInt();
	pts_count = Reader.ReadInt();
	date = Reader.TGReadDate();
	if((Flags & (1 << 9)) != 0) 
	{
	media = reinterpret_cast<PRIVATE::MessageMedia* >(Reader.TGReadObject());
	}
	if((Flags & (1 << 7)) != 0) 
	{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len29991 = Reader.ReadInt();
	for(int32 i = 0; i < Len29991; i++)
	{
	auto X = reinterpret_cast<PRIVATE::MessageEntity*>(Reader.TGReadObject());
	entities.Add(X);
	}
	}
	this->_Responded = true;
}
UpdateShortSentMessage::~UpdateShortSentMessage()
{

}
}//end namespace block
