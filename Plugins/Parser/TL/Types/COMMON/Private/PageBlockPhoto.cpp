#include "../Public/PageBlockPhoto.h"


//begin namespace block
namespace COMMON
{

PageBlockPhoto::PageBlockPhoto()
{
	this->_ConstructorID = -2103851287;
}

PageBlockPhoto::PageBlockPhoto(unsigned long long photo_id, PRIVATE::RichText* caption)
{
	this->_ConstructorID = -2103851287;
	this->photo_id = photo_id;
	this->caption = caption;
}
void PageBlockPhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->photo_id);
	this->caption->OnSend(Writer);
}


void PageBlockPhoto::OnResponce(BinaryReader& Reader)
{
	photo_id = Reader.ReadLong();
	caption = reinterpret_cast<PRIVATE::RichText*>(Reader.TGReadObject());
}
PageBlockPhoto::~PageBlockPhoto()
{

}
}//end namespace block
