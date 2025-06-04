#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <array>
#include <iterator>   // for distance

using namespace std;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Project1 {
    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Collections::Generic;

    public ref class Form2 : public Form {
    private:
        int frames;
        int pages;
        List<int>^ refString;
        DataGridView^ dataGridViewDetails;
        TabControl^ tabControlDetails;

    public:
        Form2(int f, int p, List<int>^ refStr) {
            InitializeComponent();
            frames = f;
            pages = p;
            refString = refStr;

            // Updated label with better formatting
            labelInput->Text = String::Format("Frames: {0}, Pages: {1}\nReference: {2}",
                frames, pages, String::Join(" ", refStr));

            InitializeAdditionalComponents();
        }

    protected:
        ~Form2() {
            if (components) delete components;
        }

    private:
        // Controls
        ComboBox^ comboBoxAlgorithm;
        Button^ buttonRun;
        Button^ buttonDetails;
        Label^ labelAlgorithm;
        Label^ labelOutput;
        Label^ labelResult;
        Label^ labelInput;
        Label^ labelHeader;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void) {
            // Main form setup
            this->SuspendLayout();
            this->BackColor = System::Drawing::Color::FromArgb(230, 230, 250);
            this->ClientSize = System::Drawing::Size(600, 400);
            this->Text = L"Smart Swapper - Results";

            // Header label
            this->labelHeader = gcnew Label();
            this->labelHeader->AutoSize = true;
            this->labelHeader->Font = gcnew System::Drawing::Font(L"Segoe UI", 14, FontStyle::Bold);
            this->labelHeader->ForeColor = System::Drawing::Color::FromArgb(102, 51, 153);
            this->labelHeader->Location = System::Drawing::Point(200, 20);
            this->labelHeader->Text = L"ALGORITHM RESULTS";
            this->Controls->Add(labelHeader);

            // Input label
            this->labelInput = gcnew Label();
            this->labelInput->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F);
            this->labelInput->Location = System::Drawing::Point(50, 60);
            this->labelInput->Size = System::Drawing::Size(500, 40);
            this->Controls->Add(labelInput);

            // Algorithm selection
            this->labelAlgorithm = gcnew Label();
            this->labelAlgorithm->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F);
            this->labelAlgorithm->Location = System::Drawing::Point(50, 110);
            this->labelAlgorithm->Text = L"Select Algorithm:";
            this->labelAlgorithm->AutoSize = true;
            this->Controls->Add(labelAlgorithm);

            this->comboBoxAlgorithm = gcnew ComboBox();
            this->comboBoxAlgorithm->DropDownStyle = ComboBoxStyle::DropDownList;
            this->comboBoxAlgorithm->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F);
            this->comboBoxAlgorithm->Items->AddRange(gcnew cli::array<Object^>(4) {
                "FIFO", "LRU", "Optimal", "All Algorithms"
            });
            this->comboBoxAlgorithm->Location = System::Drawing::Point(170, 107);
            this->comboBoxAlgorithm->Size = System::Drawing::Size(150, 24);
            this->comboBoxAlgorithm->BackColor = System::Drawing::Color::White;
            this->Controls->Add(comboBoxAlgorithm);

            // Run button
            this->buttonRun = gcnew Button();
            this->buttonRun->BackColor = System::Drawing::Color::FromArgb(153, 102, 204);
            this->buttonRun->FlatStyle = FlatStyle::Flat;
            this->buttonRun->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, FontStyle::Bold);
            this->buttonRun->ForeColor = System::Drawing::Color::White;
            this->buttonRun->Location = System::Drawing::Point(170, 150);
            this->buttonRun->Size = System::Drawing::Size(150, 35);
            this->buttonRun->Text = L"RUN";
            this->buttonRun->Click += gcnew EventHandler(this, &Form2::buttonRun_Click);
            this->Controls->Add(buttonRun);

            // Results labels
            this->labelOutput = gcnew Label();
            this->labelOutput->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F);
            this->labelOutput->Location = System::Drawing::Point(50, 200);
            this->labelOutput->AutoSize = true;
            this->Controls->Add(labelOutput);

            this->labelResult = gcnew Label();
            this->labelResult->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, FontStyle::Bold);
            this->labelResult->ForeColor = System::Drawing::Color::FromArgb(0, 128, 0);
            this->labelResult->Location = System::Drawing::Point(50, 230);
            this->labelResult->AutoSize = true;
            this->Controls->Add(labelResult);

            this->ResumeLayout(false);
        }

        void InitializeAdditionalComponents() {
            // Details button
            this->buttonDetails = gcnew Button();
            this->buttonDetails->BackColor = System::Drawing::Color::FromArgb(153, 102, 204);
            this->buttonDetails->FlatStyle = FlatStyle::Flat;
            this->buttonDetails->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, FontStyle::Bold);
            this->buttonDetails->ForeColor = System::Drawing::Color::White;
            this->buttonDetails->Location = System::Drawing::Point(350, 150);
            this->buttonDetails->Size = System::Drawing::Size(150, 35);
            this->buttonDetails->Text = L"SHOW DETAILS";
            this->buttonDetails->Click += gcnew EventHandler(this, &Form2::buttonDetails_Click);
            this->buttonDetails->Visible = false; // Initially hidden
            this->Controls->Add(buttonDetails);

            // Tab control for algorithm details
            this->tabControlDetails = gcnew TabControl();
            this->tabControlDetails->Location = Point(50, 270);
            this->tabControlDetails->Size = System::Drawing::Size(500, 300);            this->tabControlDetails->Visible = false;
            this->Controls->Add(tabControlDetails);
        }

        void buttonRun_Click(Object^ sender, EventArgs^ e) {
            if (comboBoxAlgorithm->SelectedItem == nullptr) {
                labelOutput->ForeColor = Color::Red;
                labelOutput->Text = "Please select an algorithm!";
                return;
            }

            // Convert managed list to native array
            int* ref_arr = new int[pages];
            for (int i = 0; i < pages; ++i)
                ref_arr[i] = refString[i];

            String^ selected = comboBoxAlgorithm->SelectedItem->ToString();
            int fifoFaults = 0, lruFaults = 0, optFaults = 0;

            if (selected == "FIFO") {
                fifoFaults = simulateFIFO(ref_arr, pages, frames);
                labelOutput->ForeColor = Color::Black;
                labelOutput->Text = "FIFO Page Faults: " + fifoFaults.ToString();
                labelResult->Text = "";
            }
            else if (selected == "LRU") {
                lruFaults = simulateLRU(ref_arr, pages, frames);
                labelOutput->ForeColor = Color::Black;
                labelOutput->Text = "LRU Page Faults: " + lruFaults.ToString();
                labelResult->Text = "";
            }
            else if (selected == "Optimal") {
                optFaults = simulateOptimal(ref_arr, pages, frames);
                labelOutput->ForeColor = Color::Black;
                labelOutput->Text = "Optimal Page Faults: " + optFaults.ToString();
                labelResult->Text = "";
            }
            else if (selected == "All Algorithms") {
                fifoFaults = simulateFIFO(ref_arr, pages, frames);
                lruFaults = simulateLRU(ref_arr, pages, frames);
                optFaults = simulateOptimal(ref_arr, pages, frames);

                labelOutput->ForeColor = Color::Black;
                labelOutput->Text = String::Format("FIFO: {0}, LRU: {1}, Optimal: {2}",
                    fifoFaults, lruFaults, optFaults);

                String^ best;
                int minFaults = min({ fifoFaults, lruFaults, optFaults });
                if (minFaults == optFaults) best = "Optimal";
                else if (minFaults == lruFaults) best = "LRU";
                else best = "FIFO";

                labelResult->Text = "Best Algorithm: " + best;
            }

            delete[] ref_arr;

            // Show details button after running
            buttonDetails->Visible = true;
            this->ClientSize = System::Drawing::Size(600, 400);
        }

        void buttonDetails_Click(Object^ sender, EventArgs^ e) {
            if (tabControlDetails->Visible) {
                tabControlDetails->Visible = false;
                this->ClientSize = System::Drawing::Size(600, 400);
                buttonDetails->Text = "SHOW DETAILS";
                tabControlDetails->TabPages->Clear();
            }
            else {
                // Convert managed list to native array
                int* ref_arr = new int[pages];
                for (int i = 0; i < pages; ++i)
                    ref_arr[i] = refString[i];

                String^ selected = comboBoxAlgorithm->SelectedItem->ToString();
                tabControlDetails->TabPages->Clear();

                if (selected == "FIFO") {
                    CreateDetailsTab("FIFO", GenerateFIFODetails(ref_arr, pages, frames));
                }
                else if (selected == "LRU") {
                    CreateDetailsTab("LRU", GenerateLRUDetails(ref_arr, pages, frames));
                }
                else if (selected == "Optimal") {
                    CreateDetailsTab("Optimal", GenerateOptimalDetails(ref_arr, pages, frames));
                }
                else if (selected == "All Algorithms") {
                    CreateDetailsTab("FIFO", GenerateFIFODetails(ref_arr, pages, frames));
                    CreateDetailsTab("LRU", GenerateLRUDetails(ref_arr, pages, frames));
                    CreateDetailsTab("Optimal", GenerateOptimalDetails(ref_arr, pages, frames));
                }

                delete[] ref_arr;

                tabControlDetails->Visible = true;
                this->ClientSize = System::Drawing::Size(600, 600);
                buttonDetails->Text = "HIDE DETAILS";
            }
        }

        void CreateDetailsTab(String^ algorithmName, List<List<String^>^>^ details) {
            TabPage^ tabPage = gcnew TabPage(algorithmName);
            DataGridView^ dataGridView = gcnew DataGridView();
            dataGridView->Dock = DockStyle::Fill;
            dataGridView->ReadOnly = true;
            dataGridView->AllowUserToAddRows = false;
            dataGridView->AllowUserToDeleteRows = false;
            dataGridView->AllowUserToResizeRows = false;
            dataGridView->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
            dataGridView->RowHeadersVisible = false;
            dataGridView->BackgroundColor = Color::White;

            // Add columns first
            for (int i = 0; i < details[0]->Count; i++)
            {
                DataGridViewTextBoxColumn^ column = gcnew DataGridViewTextBoxColumn();
                column->HeaderText = details[0][i]; // Set header text immediately
                column->Name = "Column" + i;       // Give each column a unique name
                column->SortMode = DataGridViewColumnSortMode::NotSortable;
                dataGridView->Columns->Add(column);
            }

            // Add rows (skip header row)
            for (int i = 1; i < details->Count; i++)
            {
                // Create a new row
                DataGridViewRow^ row = gcnew DataGridViewRow();
                row->CreateCells(dataGridView);

                // Fill the row with data
                for (int j = 0; j < details[i]->Count; j++)
                {
                    row->Cells[j]->Value = details[i][j];

                    // Highlight page faults if this is the last column
                    if (j == details[i]->Count - 1 && details[i][j] == "Yes")
                    {
                        row->Cells[j]->Style->ForeColor = Color::Red;
                        row->Cells[j]->Style->Font = gcnew System::Drawing::Font(
                            dataGridView->Font, FontStyle::Bold);
                    }
                }

                // Add the completed row to the grid
                dataGridView->Rows->Add(row);
            }

            // Auto-resize columns to fit content
            dataGridView->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells);
            // Style the grid
            dataGridView->DefaultCellStyle->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 9);
            dataGridView->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 9, FontStyle::Bold);
            dataGridView->AlternatingRowsDefaultCellStyle->BackColor = Color::FromArgb(240, 240, 240);

            tabPage->Controls->Add(dataGridView);
            tabControlDetails->TabPages->Add(tabPage);
        }

        List<List<String^>^>^ GenerateFIFODetails(const int ref_str[], int total_pages, int total_frames) {
            List<List<String^>^>^ details = gcnew List<List<String^>^>();
            vector<int> frames(total_frames, -1);
            int index = 0;

            // Create header row
            List<String^>^ header = gcnew List<String^>();
            header->Add("Step");
            header->Add("Reference");
            for (int i = 0; i < total_frames; i++) {
                header->Add("Frame " + (i + 1).ToString());
            }
            header->Add("Page Fault");
            details->Add(header);

            for (int i = 0; i < total_pages; ++i) {
                List<String^>^ row = gcnew List<String^>();
                row->Add(i.ToString());
                row->Add(ref_str[i].ToString());

                bool pageFault = find(frames.begin(), frames.end(), ref_str[i]) == frames.end();
                if (pageFault) {
                    frames[index % total_frames] = ref_str[i];
                    index++;
                }

                // Add frame contents
                for (int j = 0; j < total_frames; ++j) {
                    if (frames[j] == -1) {
                        row->Add("-");
                    }
                    else {
                        row->Add(frames[j].ToString() + (frames[j] == ref_str[i] && pageFault ? " *" : ""));
                    }
                }

                row->Add(pageFault ? "Yes" : "No");
                details->Add(row);
            }

            return details;
        }

        List<List<String^>^>^ GenerateLRUDetails(const int ref_str[], int total_pages, int total_frames) {
            List<List<String^>^>^ details = gcnew List<List<String^>^>();
            vector<int> frames(total_frames, -1);
            vector<int> lastUsed(total_frames, -1);
            int time = 0;

            // Create header row
            List<String^>^ header = gcnew List<String^>();
            header->Add("Step");
            header->Add("Reference");
            for (int i = 0; i < total_frames; i++) {
                header->Add("Frame " + (i + 1).ToString() + " (Last Used)");
            }
            header->Add("Page Fault");
            details->Add(header);

            for (int i = 0; i < total_pages; ++i) {
                time++;
                List<String^>^ row = gcnew List<String^>();
                row->Add(i.ToString());
                row->Add(ref_str[i].ToString());

                auto it = find(frames.begin(), frames.end(), ref_str[i]);
                bool pageFault = it == frames.end();

                if (!pageFault) {
                    lastUsed[it - frames.begin()] = time;
                }
                else {
                    int empty = find(frames.begin(), frames.end(), -1) - frames.begin();
                    if (empty < total_frames) {
                        frames[empty] = ref_str[i];
                        lastUsed[empty] = time;
                    }
                    else {
                        int lru = min_element(lastUsed.begin(), lastUsed.end()) - lastUsed.begin();
                        frames[lru] = ref_str[i];
                        lastUsed[lru] = time;
                    }
                }

                // Add frame contents
                for (int j = 0; j < total_frames; ++j) {
                    if (frames[j] == -1) {
                        row->Add("-");
                    }
                    else {
                        row->Add(frames[j].ToString() + " (" + lastUsed[j].ToString() + ")" +
                            (frames[j] == ref_str[i] && pageFault ? " *" : ""));
                    }
                }

                row->Add(pageFault ? "Yes" : "No");
                details->Add(row);
            }

            return details;
        }

        List<List<String^>^>^ GenerateOptimalDetails(const int ref_str[], int total_pages, int total_frames) {
            List<List<String^>^>^ details = gcnew List<List<String^>^>();
            vector<int> frames;

            // Create header row
            List<String^>^ header = gcnew List<String^>();
            header->Add("Step");
            header->Add("Reference");
            for (int i = 0; i < total_frames; i++) {
                header->Add("Frame " + (i + 1).ToString() + " (Next Use)");
            }
            header->Add("Page Fault");
            details->Add(header);

            for (int i = 0; i < total_pages; ++i) {
                List<String^>^ row = gcnew List<String^>();
                row->Add(i.ToString());
                row->Add(ref_str[i].ToString());

                bool pageFault = find(frames.begin(), frames.end(), ref_str[i]) == frames.end();

                if (pageFault) {
                    if (frames.size() < total_frames) {
                        frames.push_back(ref_str[i]);
                    }
                    else {
                        int idx = predict(ref_str, total_pages, frames, i + 1);
                        frames[idx] = ref_str[i];
                    }
                }

                // Add frame contents
                for (int j = 0; j < total_frames; ++j) {
                    if (j >= frames.size()) {
                        row->Add("-");
                        continue;
                    }

                    // Find next use
                    int nextUse = -1;
                    for (int k = i + 1; k < total_pages; ++k) {
                        if (ref_str[k] == frames[j]) {
                            nextUse = k;
                            break;
                        }
                    }

                    String^ nextUseStr = nextUse == -1 ? "never" : nextUse.ToString();
                    row->Add(frames[j].ToString() + " (" + nextUseStr + ")" +
                        (frames[j] == ref_str[i] && pageFault ? " *" : ""));
                }

                row->Add(pageFault ? "Yes" : "No");
                details->Add(row);
            }

            return details;
        }

        int simulateFIFO(const int ref_str[], int total_pages, int total_frames) {
            vector<int> frames(total_frames, -1);
            int page_faults = 0, index = 0;
            for (int i = 0; i < total_pages; ++i) {
                if (find(frames.begin(), frames.end(), ref_str[i]) == frames.end()) {
                    frames[index % total_frames] = ref_str[i];
                    index++;
                    page_faults++;
                }
            }
            return page_faults;
        }

        int simulateLRU(const int ref_str[], int total_pages, int total_frames) {
            vector<int> frames(total_frames, -1);
            vector<int> lastUsed(total_frames, -1);
            int page_faults = 0;
            int time = 0;

            for (int i = 0; i < total_pages; ++i) {
                time++;
                auto it = find(frames.begin(), frames.end(), ref_str[i]);

                if (it != frames.end()) {
                    // Page found in frames
                    lastUsed[distance(frames.begin(), it)] = time;
                }
                else {
                    // Page fault
                    page_faults++;
                    auto empty_it = find(frames.begin(), frames.end(), -1);

                    if (empty_it != frames.end()) {
                        // Empty frame available
                        size_t empty_pos = distance(frames.begin(), empty_it);
                        frames[empty_pos] = ref_str[i];
                        lastUsed[empty_pos] = time;
                    }
                    else {
                        // Need to replace a page
                        size_t lru_pos = distance(lastUsed.begin(),
                            min_element(lastUsed.begin(), lastUsed.end()));
                        frames[lru_pos] = ref_str[i];
                        lastUsed[lru_pos] = time;
                    }
                }
            }
            return page_faults;
        }

        int predict(const int ref_str[], int total_pages, const vector<int>& frames, int index) {
            int result = -1, farthest = index;
            for (int i = 0; i < frames.size(); i++) {
                int j;
                for (j = index; j < total_pages; j++) {
                    if (frames[i] == ref_str[j]) {
                        if (j > farthest) {
                            farthest = j;
                            result = i;
                        }
                        break;
                    }
                }
                if (j == total_pages) return i;
            }
            return result == -1 ? 0 : result;
        }

        int simulateOptimal(const int ref_str[], int total_pages, int total_frames) {
            vector<int> frames;
            int page_faults = 0;
            for (int i = 0; i < total_pages; ++i) {
                if (find(frames.begin(), frames.end(), ref_str[i]) != frames.end())
                    continue;
                if (frames.size() < total_frames)
                    frames.push_back(ref_str[i]);
                else {
                    int idx = predict(ref_str, total_pages, frames, i + 1);
                    frames[idx] = ref_str[i];
                }
                page_faults++;
            }
            return page_faults;
        }
    };
}