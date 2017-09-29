#include "../Public/TopPeerCategoryCorrespondents.h"


//begin namespace block
namespace COMMON
{

TopPeerCategoryCorrespondents::TopPeerCategoryCorrespondents()
{
	this->_ConstructorID = 104314861;
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
	this->_Responded = true;
}
TopPeerCategoryCorrespondents::~TopPeerCategoryCorrespondents()
{

}
}//end namespace block
