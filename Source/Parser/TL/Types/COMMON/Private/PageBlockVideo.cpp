#include "../Public/PageBlockVideo.h"


//begin namespace block
namespace COMMON
{

PageBlockVideo::PageBlockVideo()
{
	this->_ConstructorID = -640214938;
}

PageBlockVideo::PageBlockVideo(bool autoplay, bool loop, unsigned long long video_id, TLBaseObject*  caption)
{
	this->_ConstructorID = -640214938;
	this->autoplay = autoplay;
	this->loop = loop;
	this->video_id = video_id;
	this->caption = caption;
}
void PageBlockVideo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(autoplay)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(loop)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteLong(this->video_id);
	this->caption->OnSend(Writer);
}


void PageBlockVideo::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		autoplay = true;
	}
	if((Flags & (1 << 1)) != 0) 
	{
		loop = true;
	}
	video_id = Reader.ReadLong();
	caption = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
PageBlockVideo::~PageBlockVideo()
{
	if(this->caption)
	{
		delete this->caption;
	}
}
}//end namespace block
