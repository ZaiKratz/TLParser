#include "../Public/ChannelAdminLogEventActionChangeStickerSet.h"


//begin namespace block
namespace COMMON
{

ChannelAdminLogEventActionChangeStickerSet::ChannelAdminLogEventActionChangeStickerSet()
{
	this->_ConstructorID = -1312568665;
}

ChannelAdminLogEventActionChangeStickerSet::ChannelAdminLogEventActionChangeStickerSet(PRIVATE::InputStickerSet*  prev_stickerset, PRIVATE::InputStickerSet*  new_stickerset)
{
	this->_ConstructorID = -1312568665;
	this->prev_stickerset = prev_stickerset;
	this->new_stickerset = new_stickerset;
}
void ChannelAdminLogEventActionChangeStickerSet::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->prev_stickerset->OnSend(Writer);
	this->new_stickerset->OnSend(Writer);
}


void ChannelAdminLogEventActionChangeStickerSet::OnResponce(BinaryReader& Reader)
{
	prev_stickerset = reinterpret_cast<PRIVATE::InputStickerSet* >(Reader.TGReadObject());
	new_stickerset = reinterpret_cast<PRIVATE::InputStickerSet* >(Reader.TGReadObject());
	this->_Responded = true;
}
ChannelAdminLogEventActionChangeStickerSet::~ChannelAdminLogEventActionChangeStickerSet()
{

}
}//end namespace block
