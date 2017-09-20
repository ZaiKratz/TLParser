#include "../Public/PageBlockAudio.h"


//begin namespace block
namespace COMMON
{

PageBlockAudio::PageBlockAudio()
{
	this->_ConstructorID = 2132457521;
}

PageBlockAudio::PageBlockAudio(unsigned long long audio_id, PRIVATE::RichText* caption)
{
	this->_ConstructorID = 2132457521;
	this->audio_id = audio_id;
	this->caption = caption;
}
void PageBlockAudio::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->audio_id);
	this->caption->OnSend(Writer);
}


void PageBlockAudio::OnResponce(BinaryReader& Reader)
{
	audio_id = Reader.ReadLong();
	caption = reinterpret_cast<PRIVATE::RichText*>(Reader.TGReadObject());
}
PageBlockAudio::~PageBlockAudio()
{

}
}//end namespace block
