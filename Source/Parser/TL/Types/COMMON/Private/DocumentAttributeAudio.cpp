#include "../Public/DocumentAttributeAudio.h"


//begin namespace block
namespace COMMON
{

DocumentAttributeAudio::DocumentAttributeAudio()
{
	this->_ConstructorID = -1739392570;
}

DocumentAttributeAudio::DocumentAttributeAudio(bool voice, int32 duration, FString title, FString performer, TArray<uint8>  waveform)
{
	this->_ConstructorID = -1739392570;
	this->voice = voice;
	this->duration = duration;
	this->title = title;
	this->performer = performer;
	this->waveform = waveform;
}
void DocumentAttributeAudio::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(voice)
	{
		Flags |= (1 << 10);
	}
	else
	{
		Flags |= 0;
	}
	if(!title.IsEmpty())
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!performer.IsEmpty())
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(waveform.Num())
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->duration);
	Writer.TGWriteString(this->title);
	Writer.TGWriteString(this->performer);
	if(this->waveform.Num())
	{
	Writer.TGWriteBytes((unsigned char*)this->waveform.GetData(), this->waveform.Num());
	}
}


void DocumentAttributeAudio::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 10)) != 0) 
	{
		voice = true;
	}
	duration = Reader.ReadInt();
	if((Flags & (1 << 0)) != 0) 
	{
	title = Reader.TGReadString();
	}
	if((Flags & (1 << 1)) != 0) 
	{
	performer = Reader.TGReadString();
	}
	if((Flags & (1 << 2)) != 0) 
	{
	waveform = Reader.TGReadBytes();
	}
	this->_Responded = true;
}
DocumentAttributeAudio::~DocumentAttributeAudio()
{

}
}//end namespace block
