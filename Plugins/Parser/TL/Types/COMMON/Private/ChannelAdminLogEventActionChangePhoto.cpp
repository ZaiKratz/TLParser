#include "../Public/ChannelAdminLogEventActionChangePhoto.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEventActionChangePhoto::ChannelAdminLogEventActionChangePhoto()
{
	this->_ConstructorID = -1017827400;
}

ChannelAdminLogEventActionChangePhoto::ChannelAdminLogEventActionChangePhoto(COMMON::ChatPhoto* prev_photo, COMMON::ChatPhoto* new_photo)
{
	this->_ConstructorID = -1017827400;
	this->prev_photo = prev_photo;
	this->new_photo = new_photo;
}
void ChannelAdminLogEventActionChangePhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->prev_photo->OnSend(Writer);
	this->new_photo->OnSend(Writer);
}


void ChannelAdminLogEventActionChangePhoto::OnResponce(BinaryReader& Reader)
{
	prev_photo = reinterpret_cast<COMMON::ChatPhoto*>(Reader.TGReadObject());
	new_photo = reinterpret_cast<COMMON::ChatPhoto*>(Reader.TGReadObject());
}
ChannelAdminLogEventActionChangePhoto::~ChannelAdminLogEventActionChangePhoto()
{

}
}//end namespace block
