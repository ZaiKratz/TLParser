#include "../Public/TopPeerCategoryGroups.h"


//begin namespace block
namespace COMMON
{

TopPeerCategoryGroups::TopPeerCategoryGroups()
{
	this->_ConstructorID = -1122524854;
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
	this->_Responded = true;
}
TopPeerCategoryGroups::~TopPeerCategoryGroups()
{
}
}//end namespace block
