#include "../Public/TopPeerCategoryGroups.h"


//begin namespace block
namespace COMMON
{

TopPeerCategoryGroups::TopPeerCategoryGroups()
{
	this->_ConstructorID = 1252071357;
}
void TopPeerCategoryGroups::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void TopPeerCategoryGroups::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
TopPeerCategoryGroups::~TopPeerCategoryGroups()
{

}
}//end namespace block
