#pragma once
#include "Form21.h"

namespace Project1 {

    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();
        }

    protected:
        ~Form1()
        {
            if (components)
                delete components;
        }

    private:
        // Controls declaration
        System::Windows::Forms::Label^ labelFrames;
        System::Windows::Forms::TextBox^ textBoxFrames;
        System::Windows::Forms::Label^ labelPages;
        System::Windows::Forms::TextBox^ textBoxPages;
        System::Windows::Forms::Label^ labelRefString;
        System::Windows::Forms::TextBox^ textBoxRefString;
        System::Windows::Forms::Button^ buttonSubmit;
        System::Windows::Forms::Label^ labelStatus;
        System::Windows::Forms::Label^ labelHeader;
        System::ComponentModel::Container^ components;

    private:
        // InitializeComponent method
        void InitializeComponent(void)
        {
            this->labelHeader = (gcnew System::Windows::Forms::Label());
            this->labelFrames = (gcnew System::Windows::Forms::Label());
            this->textBoxFrames = (gcnew System::Windows::Forms::TextBox());
            this->labelPages = (gcnew System::Windows::Forms::Label());
            this->textBoxPages = (gcnew System::Windows::Forms::TextBox());
            this->labelRefString = (gcnew System::Windows::Forms::Label());
            this->textBoxRefString = (gcnew System::Windows::Forms::TextBox());
            this->buttonSubmit = (gcnew System::Windows::Forms::Button());
            this->labelStatus = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // labelHeader
            // 
            this->labelHeader->AutoSize = true;
            this->labelHeader->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold));
            this->labelHeader->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(102)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
                static_cast<System::Int32>(static_cast<System::Byte>(153)));
            this->labelHeader->Location = System::Drawing::Point(116, 28);
            this->labelHeader->Name = L"labelHeader";
            this->labelHeader->Size = System::Drawing::Size(216, 32);
            this->labelHeader->TabIndex = 0;
            this->labelHeader->Text = L"SMART SWAPPER";
            this->labelHeader->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // labelFrames
            // 
            this->labelFrames->AutoSize = true;
            this->labelFrames->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
            this->labelFrames->Location = System::Drawing::Point(49, 86);
            this->labelFrames->Name = L"labelFrames";
            this->labelFrames->Size = System::Drawing::Size(67, 20);
            this->labelFrames->TabIndex = 1;
            this->labelFrames->Text = L"Frames:";
            // 
            // textBoxFrames
            // 
            this->textBoxFrames->BackColor = System::Drawing::Color::White;
            this->textBoxFrames->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
            this->textBoxFrames->Location = System::Drawing::Point(206, 84);
            this->textBoxFrames->Name = L"textBoxFrames";
            this->textBoxFrames->Size = System::Drawing::Size(150, 22);
            this->textBoxFrames->TabIndex = 2;
            // 
            // labelPages
            // 
            this->labelPages->AutoSize = true;
            this->labelPages->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
            this->labelPages->Location = System::Drawing::Point(49, 135);
            this->labelPages->Name = L"labelPages";
            this->labelPages->Size = System::Drawing::Size(58, 20);
            this->labelPages->TabIndex = 3;
            this->labelPages->Text = L"Pages:";
            // 
            // textBoxPages
            // 
            this->textBoxPages->BackColor = System::Drawing::Color::White;
            this->textBoxPages->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
            this->textBoxPages->Location = System::Drawing::Point(206, 135);
            this->textBoxPages->Name = L"textBoxPages";
            this->textBoxPages->Size = System::Drawing::Size(150, 22);
            this->textBoxPages->TabIndex = 4;
            // 
            // labelRefString
            // 
            this->labelRefString->AutoSize = true;
            this->labelRefString->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
            this->labelRefString->Location = System::Drawing::Point(49, 182);
            this->labelRefString->Name = L"labelRefString";
            this->labelRefString->Size = System::Drawing::Size(134, 20);
            this->labelRefString->TabIndex = 5;
            this->labelRefString->Text = L"Reference String:";
            // 
            // textBoxRefString
            // 
            this->textBoxRefString->BackColor = System::Drawing::Color::White;
            this->textBoxRefString->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
            this->textBoxRefString->Location = System::Drawing::Point(206, 182);
            this->textBoxRefString->Name = L"textBoxRefString";
            this->textBoxRefString->Size = System::Drawing::Size(200, 22);
            this->textBoxRefString->TabIndex = 6;
            // 
            // buttonSubmit
            // 
            this->buttonSubmit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(153)), static_cast<System::Int32>(static_cast<System::Byte>(102)),
                static_cast<System::Int32>(static_cast<System::Byte>(204)));
            this->buttonSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->buttonSubmit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold));
            this->buttonSubmit->ForeColor = System::Drawing::Color::White;
            this->buttonSubmit->Location = System::Drawing::Point(150, 256);
            this->buttonSubmit->Name = L"buttonSubmit";
            this->buttonSubmit->Size = System::Drawing::Size(150, 35);
            this->buttonSubmit->TabIndex = 7;
            this->buttonSubmit->Text = L"SUBMIT";
            this->buttonSubmit->UseVisualStyleBackColor = false;
            this->buttonSubmit->Click += gcnew System::EventHandler(this, &Form1::buttonSubmit_Click);
            // 
            // labelStatus
            // 
            this->labelStatus->AutoSize = true;
            this->labelStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
            this->labelStatus->Location = System::Drawing::Point(50, 240);
            this->labelStatus->Name = L"labelStatus";
            this->labelStatus->Size = System::Drawing::Size(0, 16);
            this->labelStatus->TabIndex = 8;
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)));
            this->ClientSize = System::Drawing::Size(458, 346);
            this->Controls->Add(this->labelStatus);
            this->Controls->Add(this->buttonSubmit);
            this->Controls->Add(this->textBoxRefString);
            this->Controls->Add(this->labelRefString);
            this->Controls->Add(this->textBoxPages);
            this->Controls->Add(this->labelPages);
            this->Controls->Add(this->textBoxFrames);
            this->Controls->Add(this->labelFrames);
            this->Controls->Add(this->labelHeader);
            this->Name = L"Form1";
            this->Text = L"Smart Swapper - Page Replacement";
            this->ResumeLayout(false);
            this->PerformLayout();

        }

    private:
        System::Void buttonSubmit_Click(System::Object^ sender, System::EventArgs^ e)
        {
            int frames, pages;
            labelStatus->ForeColor = System::Drawing::Color::Red;

            try {
                frames = Int32::Parse(textBoxFrames->Text);
                pages = Int32::Parse(textBoxPages->Text);
                System::String^ rawRef = textBoxRefString->Text;

                // Split the reference string
                cli::array<System::String^>^ rawArray = rawRef->Split(' ');

                // Validate and store reference string
                System::Collections::Generic::List<int>^ refList = gcnew System::Collections::Generic::List<int>();
                for each (System::String ^ s in rawArray)
                {
                    if (!System::String::IsNullOrWhiteSpace(s))
                    {
                        try {
                            int val = Int32::Parse(s);
                            refList->Add(val);
                        }
                        catch (...) {
                            labelStatus->Text = "Reference string contains invalid numbers!";
                            return;
                        }
                    }
                }

                if (frames <= 0 || pages <= 0) {
                    labelStatus->Text = "Frames and pages must be positive integers.";
                    return;
                }
                if (refList->Count != pages) {
                    labelStatus->Text = "Reference string must contain exactly " + pages + " numbers.";
                    return;
                }

                labelStatus->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                    static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
                labelStatus->Text = "Input accepted!";

                // Open Form2 and pass data
                Form2^ f2 = gcnew Form2(frames, pages, refList);
                f2->Show();
                this->Hide();
            }
            catch (System::Exception^ ex) {
                labelStatus->Text = "Invalid input! " + ex->Message;
            }
        }
    };
}