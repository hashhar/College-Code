using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Controls;

namespace Cocomo
{
    public enum CocomoModel
    {
        Basic,
        Intermediate
    }

    public enum ProjectType
    {
        Organic,
        SemiDetached,
        Embedded
    }

    public enum CostDriversValue
    {
        VeryLow,
        Low,
        Nominal,
        High,
        VeryHigh,
        ExtraHigh
    }

    public class CostDriverClass
    {
        public CostDriverClass(string costDriversLabel, double[] costDriversRatings)
        {
            CostDriversLabel = costDriversLabel;
            CostDriversRatings = costDriversRatings;
        }

        public CostDriversValue CostDriversValue { get; set; }
        public List<string> CostDriversValueEnums
        {
            get
            {
                var enums = new List<string>();
                for (int i = 0; i < CostDriversRatings.Length; ++i)
                {
                    if (Math.Abs(CostDriversRatings[i]) > 0.0)
                    {
                        enums.Add(Enum.GetNames(typeof(CostDriversValue))[i]);
                    }
                }
                return enums;
            }
        }

        public string CostDriversLabel { get; set; }
        public double[] CostDriversRatings { get; set; }
    }

    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow
    {
        private readonly double[][] _costDriverRatings = {
            // Product attributes.
            new[] {0.75, 0.88, 1.00, 1.15, 1.40, 0.0},
            new[] {0.0, 0.94, 1.00, 1.08, 1.16, 0.0},
            new[] {0.70, 0.85, 1.00, 1.15, 1.30, 1.65},
            // Hardware attributes.
            new[] {0.0, 0.0, 1.00, 1.11, 1.30, 1.66},
            new[] {0.0, 0.0, 1.00, 1.06, 1.21, 1.56},
            new[] {0.0, 0.87, 1.00, 1.15, 1.30, 0.0},
            new[] {0.0, 0.87, 1.00, 1.07, 1.15, 0.0},
            // Personnel attributes.
            new[] {1.46, 1.19, 1.00, 0.86, 0.71, 0.0},
            new[] {1.29, 1.13, 1.00, 0.91, 0.82, 0.0},
            new[] {1.42, 1.17, 1.00, 0.86, 0.70, 0.0},
            new[] {1.21, 1.10, 1.00, 0.90, 0.0, 0.0},
            new[] {1.14, 1.07, 1.00, 0.95, 0.0, 0.0},
            // Project attributes.
            new[] {1.24, 1.10, 1.00, 0.91, 0.82, 0.0},
            new[] {1.24, 1.10, 1.00, 0.91, 0.83, 0.0},
            new[] {1.23, 1.08, 1.00, 1.04, 1.10, 0.0}
        };

        private readonly string[] _costDriverLabels = {
            // Product attributes.
            "Required software reliability",
            "Size of application database",
            "Complexity of the product",
            // Hardware attributes.
            "Run-time performance constraints",
            "Memory constraints",
            "Volatility of the virtual machine environment",
            "Required turnabout time",
            // Personnel attributes.
            "Analyst capability",
            "Applications experience",
            "Software engineering capability",
            "Virtual machine experience",
            "Programming language experience",
            // Project attributes.
            "Application of software engineering methods",
            "Use of software tools",
            "Required development schedule"
        };

        public CocomoModel CocomoModel { get; set; }
        public IEnumerable<CocomoModel> CocomoModelEnums => Enum.GetValues(typeof(CocomoModel)).Cast<CocomoModel>();

        public double KiloLinesOfCode { get; set; }
        public ProjectType ProjectType { get; set; }

        public double Eaf
        {
            get
            {
                return CocomoModel != CocomoModel.Intermediate ? 1.0 : CostDriverClasses.Select(costDriverClass => costDriverClass.CostDriversRatings[(int)costDriverClass.CostDriversValue]).Where(val => val > 0.0).Aggregate(1.0, (current, val) => current * val);
            }
        }

        // Basic, Intermediate - A,B,C,D - Organic, SemiDetached, Embedded
        private static readonly double[][][] CoefficientMatrix = {
            // Basic array
            new []
            {
                new[]{2.4, 3.0, 3.6}, // a
                new[]{1.05,1.12,1.20}, // b
                new[]{2.5,2.5,2.5}, // c
                new[]{0.38,0.35,0.32} // d
            },
            // Intermediate array
            new []
            {
                new []{3.2,3.0,2.8}, // a
                new []{1.05,1.12,1.20}, // b
                new[]{2.5,2.5,2.5}, // c - same as basic
                new[]{0.38,0.35,0.32} // d - same as basic
            }
        };

        public double Effort { get; set; }
        public double DevelopmentTime { get; set; }
        public double EstimatedStaffSize { get; set; }
        public double Productivity { get; set; }

        private void Button_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            double a, b, c, d;
            int i = 0, j = 0;
            switch (CocomoModel)
            {
                case CocomoModel.Basic:
                    i = 0;
                    break;
                case CocomoModel.Intermediate:
                    i = 1;
                    break;
            }
            switch (ProjectType)
            {
                case ProjectType.Organic:
                    j = 0;
                    break;
                case ProjectType.SemiDetached:
                    j = 1;
                    break;
                case ProjectType.Embedded:
                    j = 2;
                    break;
            }
            a = CoefficientMatrix[i][0][j];
            b = CoefficientMatrix[i][1][j];
            c = CoefficientMatrix[i][2][j];
            d = CoefficientMatrix[i][3][j];
            Effort = Math.Round(a * Math.Pow(KiloLinesOfCode, b) * Eaf, 2);
            DevelopmentTime = Math.Round(c * Math.Pow(Effort, d), 2);
            EstimatedStaffSize = Math.Round(Effort / DevelopmentTime, 2);
            Productivity = Math.Round(KiloLinesOfCode / Effort, 2);

            // Update the text in the output boxes according to the value of the property it is bound to.
            EffortTextBox.GetBindingExpression(TextBox.TextProperty)?.UpdateTarget();
            DevelopmentTimeTextBox.GetBindingExpression(TextBox.TextProperty)?.UpdateTarget();
            EstimatedStaffSizeTextBox.GetBindingExpression(TextBox.TextProperty)?.UpdateTarget();
            ProductivityTextBox.GetBindingExpression(TextBox.TextProperty)?.UpdateTarget();
        }

        public List<CostDriverClass> CostDriverClasses = new List<CostDriverClass>();

        public MainWindow()
        {
            InitializeComponent();
            DataContext = this;

            for (int i = 0; i < 15; i++)
            {
                CostDriverClasses.Add(new CostDriverClass(_costDriverLabels[i], _costDriverRatings[i]));
            }
            CostDriversItemsControl.ItemsSource = CostDriverClasses;
            CostDriversItemsControl.IsEnabled = false;
        }

        private void KiloLinesOfCode_OnTextChanged(object sender, TextChangedEventArgs e)
        {
            if (KiloLinesOfCode < 50)
            {
                ProjectType = ProjectType.Organic;
            }
            else if (KiloLinesOfCode >= 50 && KiloLinesOfCode < 300)
            {
                ProjectType = ProjectType.SemiDetached;
            }
            else
            {
                ProjectType = ProjectType.Embedded;
            }
            // Update the text in the ProjectTypeTextBox according to the value of the property it is bound to.
            ProjectTypeTextBox.GetBindingExpression(TextBox.TextProperty)?.UpdateTarget();
        }

        private void ComboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            CostDriversItemsControl.IsEnabled = CocomoModel == CocomoModel.Intermediate;
        }
    }
}
