#pragma once
#include "Engine.h"
#include "../../../Types/Private/ReportReason.h"

#include "../../../Types/Private/ReportReason.h"

//begin namespace block
namespace COMMON
{
class InputReportReasonOther : public PRIVATE::ReportReason
{
public:
	InputReportReasonOther();
	InputReportReasonOther(FString text);

	~InputReportReasonOther();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString text;
};
} //end namespace block
