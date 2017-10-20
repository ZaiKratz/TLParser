#include "../Public/DocumentAttributeVideo.h"


//begin namespace block
namespace COMMON
{

DocumentAttributeVideo::DocumentAttributeVideo()
{
	this->_ConstructorID = 250621158;
}

DocumentAttributeVideo::DocumentAttributeVideo(bool round_message, int32 duration, int32 w, int32 h)
{
	this->_ConstructorID = 250621158;
	this->round_message = round_message;
	this->duration = duration;
	this->w = w;
	this->h = h;
}
void DocumentAttributeVideo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(round_message)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->duration);
	Writer.WriteInt(this->w);
	Writer.WriteInt(this->h);
}


void DocumentAttributeVideo::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		round_message = true;
	}
	duration = Reader.ReadInt();
	w = Reader.ReadInt();
	h = Reader.ReadInt();
	this->_Responded = true;
}
DocumentAttributeVideo::~DocumentAttributeVideo()
{
}
}//end namespace block
