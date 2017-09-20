#include "../Public/PageBlockCover.h"


//begin namespace block
namespace COMMON
{

PageBlockCover::PageBlockCover()
{
	this->_ConstructorID = 3404345;
}

PageBlockCover::PageBlockCover(PRIVATE::PageBlock* cover)
{
	this->_ConstructorID = 3404345;
	this->cover = cover;
}
void PageBlockCover::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->cover->OnSend(Writer);
}


void PageBlockCover::OnResponce(BinaryReader& Reader)
{
	cover = reinterpret_cast<PRIVATE::PageBlock*>(Reader.TGReadObject());
}
PageBlockCover::~PageBlockCover()
{

}
}//end namespace block
