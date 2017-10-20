#include "../Public/DocumentAttributeSticker.h"


//begin namespace block
namespace COMMON
{

DocumentAttributeSticker::DocumentAttributeSticker()
{
	this->_ConstructorID = 1662637586;
}

DocumentAttributeSticker::DocumentAttributeSticker(bool mask, FString alt, TLBaseObject*  stickerset, COMMON::MaskCoords*  mask_coords)
{
	this->_ConstructorID = 1662637586;
	this->mask = mask;
	this->alt = alt;
	this->stickerset = stickerset;
	this->mask_coords = mask_coords;
}
void DocumentAttributeSticker::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(mask)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(mask_coords)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteString(this->alt);
	this->stickerset->OnSend(Writer);
	if(this->mask_coords)
	{
	this->mask_coords->OnSend(Writer);
	}
}


void DocumentAttributeSticker::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 1)) != 0) 
	{
		mask = true;
	}
	alt = Reader.TGReadString();
	stickerset = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	if((Flags & (1 << 0)) != 0) 
	{
	mask_coords = reinterpret_cast<COMMON::MaskCoords* >(Reader.TGReadObject());
	}
	this->_Responded = true;
}
DocumentAttributeSticker::~DocumentAttributeSticker()
{
	if(this->stickerset)
	{
		delete this->stickerset;
	}
	if(this->mask_coords)
	{
		delete this->mask_coords;
	}
}
}//end namespace block
