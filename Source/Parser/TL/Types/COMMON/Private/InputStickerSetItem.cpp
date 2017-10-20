#include "../Public/InputStickerSetItem.h"


//begin namespace block
namespace COMMON
{

InputStickerSetItem::InputStickerSetItem()
{
	this->_ConstructorID = -6249322;
}

InputStickerSetItem::InputStickerSetItem(COMMON::InputDocument*  document, FString emoji, COMMON::MaskCoords*  mask_coords)
{
	this->_ConstructorID = -6249322;
	this->document = document;
	this->emoji = emoji;
	this->mask_coords = mask_coords;
}
void InputStickerSetItem::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(mask_coords)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->document->OnSend(Writer);
	Writer.TGWriteString(this->emoji);
	if(this->mask_coords)
	{
	this->mask_coords->OnSend(Writer);
	}
}


void InputStickerSetItem::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	document = reinterpret_cast<COMMON::InputDocument* >(Reader.TGReadObject());
	emoji = Reader.TGReadString();
	if((Flags & (1 << 0)) != 0) 
	{
	mask_coords = reinterpret_cast<COMMON::MaskCoords* >(Reader.TGReadObject());
	}
	this->_Responded = true;
}
InputStickerSetItem::~InputStickerSetItem()
{
	if(this->document)
	{
		delete this->document;
	}
	if(this->mask_coords)
	{
		delete this->mask_coords;
	}
}
}//end namespace block
