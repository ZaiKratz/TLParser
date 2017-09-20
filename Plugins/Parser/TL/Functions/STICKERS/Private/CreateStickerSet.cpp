#include "../Public/CreateStickerSet.h"


//begin namespace block
namespace STICKERS
{

CreateStickerSet::CreateStickerSet()
{
	this->_ConstructorID = 1785649307;
	this->_ContentRelated = true;
}

CreateStickerSet::CreateStickerSet(bool masks, COMMON::InputUser* user_id, FString title, FString short_name, TArray<COMMON::InputStickerSetItem*> stickers)
{
	this->_ConstructorID = 1785649307;
	this->_ContentRelated = true;
	this->masks = masks;
	this->user_id = user_id;
	this->title = title;
	this->short_name = short_name;
	this->stickers = stickers;
}
void CreateStickerSet::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!masks)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->user_id->OnSend(Writer);
	Writer.TGWriteString(this->title);
	Writer.TGWriteString(this->short_name);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->stickers.Num());
	for(auto X : this->stickers)
	{
	X->OnSend(Writer);
	}
}


void CreateStickerSet::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::StickerSet*>(Reader.TGReadObject());
}
CreateStickerSet::~CreateStickerSet()
{

}
}//end namespace block
