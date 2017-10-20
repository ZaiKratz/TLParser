#include "../Public/PageBlockPhoto.h"


//begin namespace block
namespace COMMON
{

PageBlockPhoto::PageBlockPhoto()
{
	this->_ConstructorID = -372860542;
}

PageBlockPhoto::PageBlockPhoto(unsigned long long photo_id, TLBaseObject*  caption)
{
	this->_ConstructorID = -372860542;
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
	caption = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
PageBlockPhoto::~PageBlockPhoto()
{
	if(this->caption)
	{
		delete this->caption;
	}
}
}//end namespace block
