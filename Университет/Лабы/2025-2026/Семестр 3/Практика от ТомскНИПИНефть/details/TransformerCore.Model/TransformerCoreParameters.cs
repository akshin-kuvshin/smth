// author: Danila "akshin_" Axyonov

namespace TransformerCore.Model
{
    /// <summary>
    /// Параметры сердечника трансформатора.
    /// </summary>
    public class TransformerCoreParameters
    {
        /// <summary>
        /// Общая длина сердечника трансформатора.
        /// Пересчитывается автоматически при изменении любого из _medianToothLength, _sideToothLength, _toothStepLength.
        /// </summary>
        private Parameter<double> _totalLength;

        /// <summary>
        /// Общая высота сердечника трансформатора.
        /// </summary>
        private Parameter<double> _totalHeight;

        /// <summary>
        /// Общая ширина сердечника трансформатора.
        /// </summary>
        private Parameter<double> _totalWidth;

        /// <summary>
        /// Длина срединного зубчика сердечника трансформатора.
        /// </summary>
        private Parameter<double> _medianToothLength;

        /// <summary>
        /// Длина бокового зубчика сердечника трансформатора.
        /// </summary>
        private Parameter<double> _sideToothLength;

        /// <summary>
        /// Длина шага зубчиков сердечника трансформатора.
        /// </summary>
        private Parameter<double> _toothStepLength;

        /// <summary>
        /// Высота зубчиков сердечника трансформатора.
        /// </summary>
        private Parameter<double> _toothHeight;

        /// <summary>
        /// Флаг валидности объекта.
        /// true => валиден | false => невалиден.
        /// </summary>
        private bool _isValid;

        /// <summary>
        /// Readonly-свойство общей длины сердечника трансформатора.
        /// </summary>
        public double TotalLength
        {
            get => _totalLength.Value;
        }

        /// <summary>
        /// Свойство с валидацией общей высоты сердечника трансформатора.
        /// </summary>
        public double TotalHeight
        {
            get => _totalHeight.Value;
            set
            {
                _isValid = false;
                if (!Validator.ValidateParameter(_totalHeight, value))
                {
                    throw new Exception($"Общая высота сердечника трансформатора должна быть задана в следующем диапазоне: [{Constants.MIN_TOTAL_HEIGHT:F4} - {Constants.MAX_TOTAL_HEIGHT:F4}].");
                }
                else
                {
                    _totalHeight.Value = value;
                    _isValid = true;
                }
            }
        }

        /// <summary>
        /// Свойство с валидацией общей ширины сердечника трансформатора.
        /// </summary>
        public double TotalWidth
        {
            get => _totalWidth.Value;
            set
            {
                _isValid = false;
                if (!Validator.ValidateParameter(_totalWidth, value))
                {
                    throw new Exception($"Общая ширина сердечника трансформатора должна быть задана в следующем диапазоне: [{Constants.MIN_TOTAL_WIDTH:F4} - {Constants.MAX_TOTAL_WIDTH:F4}].");
                }
                else
                {
                    _totalWidth.Value = value;
                    _isValid = true;
                }
            }
        }

        /// <summary>
        /// Свойство с валидацией длины срединного зубчика сердечника трансформатора.
        /// </summary>
        public double MedianToothLength
        {
            get => _medianToothLength.Value;
            set
            {
                _isValid = false;
                if (!Validator.ValidateParameter(_medianToothLength, value))
                {
                    throw new Exception($"Длина срединного зубчика сердечника трансформатора должна быть задана в следующем диапазоне: [{Constants.MIN_MEDIAN_TOOTH_LENGTH:F4} - {Constants.MAX_MEDIAN_TOOTH_LENGTH:F4}].");
                }
                else if (!Validator.ValidateParameter(_totalLength, value + 2 * (_sideToothLength.Value + _toothStepLength.Value)))
                {
                    throw new Exception($"Общая длина сердечника трансформатора должна быть задана в следующем диапазоне: [{Constants.MIN_TOTAL_LENGTH:F4} - {Constants.MAX_TOTAL_LENGTH:F4}].");
                }
                else
                {
                    _medianToothLength.Value = value;
                    _totalLength.Value = value + 2 * (_sideToothLength.Value + _toothStepLength.Value);
                    _isValid = true;
                }
            }
        }

        /// <summary>
        /// Свойство с валидацией длины бокового зубчика сердечника трансформатора.
        /// </summary>
        public double SideToothLength
        {
            get => _sideToothLength.Value;
            set
            {
                _isValid = false;
                if (!Validator.ValidateParameter(_sideToothLength, value))
                {
                    throw new Exception($"Длина бокового зубчика сердечника трансформатора должна быть задана в следующем диапазоне: [{Constants.MIN_SIDE_TOOTH_LENGTH:F4} - {Constants.MAX_SIDE_TOOTH_LENGTH:F4}].");
                }
                else if (!Validator.ValidateParameter(_totalLength, _medianToothLength.Value + 2 * (value + _toothStepLength.Value)))
                {
                    throw new Exception($"Общая длина сердечника трансформатора должна быть задана в следующем диапазоне: [{Constants.MIN_TOTAL_LENGTH:F4} - {Constants.MAX_TOTAL_LENGTH:F4}].");
                }
                else
                {
                    _sideToothLength.Value = value;
                    _totalLength.Value = _medianToothLength.Value + 2 * (value + _toothStepLength.Value);
                    _isValid = true;
                }
            }
        }

        /// <summary>
        /// Свойство с валидацией длины шага зубчиков сердечника трансформатора.
        /// </summary>
        public double ToothStepLength
        {
            get => _toothStepLength.Value;
            set
            {
                _isValid = false;
                if (!Validator.ValidateParameter(_toothStepLength, value))
                {
                    throw new Exception($"Длина шага зубчиков сердечника трансформатора должна быть задана в следующем диапазоне: [{Constants.MIN_TOOTH_STEP_LENGTH:F4} - {Constants.MAX_TOOTH_STEP_LENGTH:F4}].");
                }
                else if (!Validator.ValidateParameter(_totalLength, _medianToothLength.Value + 2 * (_sideToothLength.Value + value)))
                {
                    throw new Exception($"Общая длина сердечника трансформатора должна быть задана в следующем диапазоне: [{Constants.MIN_TOTAL_LENGTH:F4} - {Constants.MAX_TOTAL_LENGTH:F4}].");
                }
                else
                {
                    _toothStepLength.Value = value;
                    _totalLength.Value = _medianToothLength.Value + 2 * (_sideToothLength.Value + value);
                    _isValid = true;
                }
            }
        }

        /// <summary>
        /// Свойство с валидацией высоты зубчиков сердечника трансформатора.
        /// </summary>
        public double ToothHeight
        {
            get => _toothHeight.Value;
            set
            {
                _isValid = false;
                if (!Validator.ValidateParameter(_toothHeight, value))
                {
                    throw new Exception($"Высота зубчиков сердечника трансформатора должна быть задана в следующем диапазоне: [{Constants.MIN_TOOTH_HEIGHT:F4} - {Constants.MAX_TOOTH_HEIGHT:F4}].");
                }
                else if (value >= _totalHeight.Value)
                {
                    throw new Exception($"Высота зубчиков сердечника трансформатора должна быть строго меньше его общей высоты = {_totalHeight.Value:F4}.");
                }
                else
                {
                    _toothHeight.Value = value;
                    _isValid = true;
                }
            }
        }

        /// <summary>
        /// Readonly-свойство валидности объекта.
        /// true => валиден | false => невалиден.
        /// </summary>
        public bool IsValid
        {
            get => _isValid;
        }

        /// <summary>
        /// Конструктор по умолчанию. Определяет сердечник трансформатора типоразмера <b>Ш8x8</b>.
        /// Стандартные типоразмеры и их параметры см. по ссылке: <i>https://ferrite.ru/docs/serdechniki-konfiguratsii-sh/</i>
        /// </summary>
        public TransformerCoreParameters()
        {
            _totalLength = new Parameter<double>(Constants.MIN_TOTAL_LENGTH, 32e-3, Constants.MAX_TOTAL_LENGTH);
            _totalHeight = new Parameter<double>(Constants.MIN_TOTAL_HEIGHT, 16e-3, Constants.MAX_TOTAL_HEIGHT);
            _totalWidth = new Parameter<double>(Constants.MIN_TOTAL_WIDTH, 8e-3, Constants.MAX_TOTAL_WIDTH);
            _medianToothLength = new Parameter<double>(Constants.MIN_MEDIAN_TOOTH_LENGTH, 8e-3, Constants.MAX_MEDIAN_TOOTH_LENGTH);
            _sideToothLength = new Parameter<double>(Constants.MIN_SIDE_TOOTH_LENGTH, 4.5e-3, Constants.MAX_SIDE_TOOTH_LENGTH);
            _toothStepLength = new Parameter<double>(Constants.MIN_TOOTH_STEP_LENGTH, 7.5e-3, Constants.MAX_TOOTH_STEP_LENGTH);
            _toothHeight = new Parameter<double>(Constants.MIN_TOOTH_HEIGHT, 1.5e-3, Constants.MAX_TOOTH_HEIGHT);
            _isValid = true;
        }

        /// <summary>
        /// Конструктор с явным заданием всех независимых параметров сердечника трансформатора.
        /// </summary>
        /// <param name="initTotalHeight">Исходная общая высота сердечника транформатора.</param>
        /// <param name="initTotalWidth">Исходная общая ширина сердечника транформатора.</param>
        /// <param name="initMedianToothLength">Исходная длина срединного зубчика сердечника транформатора.</param>
        /// <param name="initSideToothLength">Исходная длина бокового зубчика сердечника транформатора.</param>
        /// <param name="initToothStepLength">Исходная длина шага зубчиков сердечника транформатора.</param>
        /// <param name="initToothHeight">Исходная высота зубчиков сердечника транформатора.</param>
        public TransformerCoreParameters(
            double initTotalHeight,
            double initTotalWidth,
            double initMedianToothLength,
            double initSideToothLength,
            double initToothStepLength,
            double initToothHeight
            ) : this()
        {
            TotalHeight = initTotalHeight;
            TotalWidth = initTotalWidth;
            MedianToothLength = initMedianToothLength;
            SideToothLength = initSideToothLength;
            ToothStepLength = initToothStepLength;
            ToothHeight = initToothHeight;
        }
    }
}
