#include "../Public/EditAbout.h"


//begin namespace block
namespace CHANNELS
{

EditAbout::EditAbout()
{
	this->_ConstructorID = 511697427;
	this->_ContentRelated = true;
}

EditAbout::EditAbout(COMMON::InputChannel* channel, FString about)
{
	this->_ConstructorID = 511697427;
	this->_ContentRelated = true;
	this->channel = channel;
	this->about = about;
}
void EditAbout::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
	Writer.TGWriteString(this->about);
}


void EditAbout::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
}
EditAbout::~EditAbout()
{

}
}//end namespace block