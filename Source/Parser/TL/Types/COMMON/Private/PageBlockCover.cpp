#include "../Public/PageBlockCover.h"


//begin namespace block
namespace COMMON
{

PageBlockCover::PageBlockCover()
{
	this->_ConstructorID = 972174080;
}

PageBlockCover::PageBlockCover(TLBaseObject*  cover)
{
	this->_ConstructorID = 972174080;
	this->cover = cover;
}
void PageBlockCover::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->cover->OnSend(Writer);
}


void PageBlockCover::OnResponce(BinaryReader& Reader)
{
	cover = reinterpret_cast<TLBaseObject* >(Reader.TGReadObject());
	this->_Responded = true;
}
PageBlockCover::~PageBlockCover()
{
	if(this->cover)
	{
		delete this->cover;
	}
}
}//end namespace block
