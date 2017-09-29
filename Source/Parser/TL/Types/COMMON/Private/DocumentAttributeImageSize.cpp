#include "../Public/DocumentAttributeImageSize.h"


//begin namespace block
namespace COMMON
{

DocumentAttributeImageSize::DocumentAttributeImageSize()
{
	this->_ConstructorID = 1815593308;
}

DocumentAttributeImageSize::DocumentAttributeImageSize(int32 w, int32 h)
{
	this->_ConstructorID = 1815593308;
	this->w = w;
	this->h = h;
}
void DocumentAttributeImageSize::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->w);
	Writer.WriteInt(this->h);
}


void DocumentAttributeImageSize::OnResponce(BinaryReader& Reader)
{
	w = Reader.ReadInt();
	h = Reader.ReadInt();
	this->_Responded = true;
}
DocumentAttributeImageSize::~DocumentAttributeImageSize()
{

}
}//end namespace block
