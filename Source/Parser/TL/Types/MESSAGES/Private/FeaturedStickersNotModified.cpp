#include "../Public/FeaturedStickersNotModified.h"


//begin namespace block
namespace MESSAGES
{

FeaturedStickersNotModified::FeaturedStickersNotModified()
{
	this->_ConstructorID = 82699215;
}
void FeaturedStickersNotModified::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void FeaturedStickersNotModified::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
FeaturedStickersNotModified::~FeaturedStickersNotModified()
{

}
}//end namespace block
