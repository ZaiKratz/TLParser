#include "../Public/TopPeerCategoryCorrespondents.h"


//begin namespace block
namespace COMMON
{

TopPeerCategoryCorrespondents::TopPeerCategoryCorrespondents()
{
	this->_ConstructorID = 64;
}
void TopPeerCategoryCorrespondents::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void TopPeerCategoryCorrespondents::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
TopPeerCategoryCorrespondents::~TopPeerCategoryCorrespondents()
{

}
}//end namespace block
